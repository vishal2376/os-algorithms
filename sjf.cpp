#include <iostream>
#include <algorithm> // for std::sort

int main() {

	const int MAX_PROCESSES = 20;
	int burst_time[MAX_PROCESSES]; // array to store burst time
	int process_id[MAX_PROCESSES]; // array to store process IDs
	int waiting_time[MAX_PROCESSES]; // array to store waiting time
	int turnaround_time[MAX_PROCESSES]; // array to store turnaround time
	int num_processes, total_waiting_time = 0, pos, temp;
	float avg_waiting_time, avg_turnaround_time;
	std::cout << "Enter number of processes: ";
	std::cin >> num_processes;
	std::cout << "\nEnter burst time:\n";
	for (int i = 0; i < num_processes; i++)
	{
		std::cout << "P" << i + 1 << ": ";
		std::cin >> burst_time[i];
		process_id[i] = i + 1; // store process IDs
	}
// Sort burst times in ascending order using selection sort algorithm
	for (int i = 0; i < num_processes; i++)
	{
		pos = i;
		for (int j = i + 1; j < num_processes; j++)
		{
			if (burst_time[j] < burst_time[pos])
			{
				pos = j;
			}
		}
// Swap burst times and process IDs
		std::swap(burst_time[i], burst_time[pos]);
		std::swap(process_id[i], process_id[pos]);
	}
	waiting_time[0] = 0; // waiting time for first process is zero
// Calculate waiting time for each process
	for (int i = 1; i < num_processes; i++)
	{
		waiting_time[i] = 0;
		for (int j = 0; j < i; j++)
		{
			waiting_time[i] += burst_time[j];
		}
		total_waiting_time += waiting_time[i]; // accumulate total waiting time
	}
	avg_waiting_time = (float)total_waiting_time / num_processes; // calculate average waiting time
	total_waiting_time = 0;
// Print table of process details
	std::cout << "\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n";
	for (int i = 0; i < num_processes; i++)
	{
		turnaround_time[i] = burst_time[i] + waiting_time[i]; // calculate turnaround time
		total_waiting_time += turnaround_time[i]; // accumulate total turnaround time
		std::cout << "P" << process_id[i] << "\t" << burst_time[i] << "\t\t"
		          << waiting_time[i] << "\t\t" << turnaround_time[i] << "\n";
	}
	avg_turnaround_time = (float)total_waiting_time / num_processes; // calculate average turnaround time
// Print average waiting and turnaround times
	std::cout << "\nAverage Waiting Time = " << avg_waiting_time
	          << "\nAverage Turnaround Time = " << avg_turnaround_time << "\n";
	return 0;
}
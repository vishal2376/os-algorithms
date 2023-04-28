#include <iostream>
void calculateWaitingTime(int processes[], int n, int burst_time[], int waiting_time[]) {
	waiting_time[0] = 0;
	for (int i = 1; i < n ; i++) {
		waiting_time[i] = burst_time[i - 1] + waiting_time[i - 1];
	}
}

void calculateTurnAroundTime(int processes[], int n, int burst_time[], int waiting_time[], int tat[]) {
	for (int i = 0; i < n ; i++) {
		tat[i] = burst_time[i] + waiting_time[i];
	}
}

void calculateAvgTime(int processes[], int n, int burst_time[]) {
	int waiting_time[n], tat[n], total_waiting_time = 0, total_tat = 0;
	calculateWaitingTime(processes, n, burst_time, waiting_time);
	calculateTurnAroundTime(processes, n, burst_time, waiting_time, tat);
	std::cout << "Processes Burst time Waiting time Turn around time" << std::endl;
	for (int i = 0; i < n; i++) {
		total_waiting_time += waiting_time[i];
		total_tat += tat[i];
		std::cout << " " << (i + 1) << " \t\t" << burst_time[i] << " \t\t" << waiting_time[i] << "\t\t" << tat[i] << std::endl;
	}
	float avg_waiting_time = (float)total_waiting_time / (float)n;
	float avg_tat = (float)total_tat / (float)n;
	std::cout << "Average waiting time = " << avg_waiting_time << std::endl;
	std::cout << "Average turn around time = " << avg_tat << std::endl;
}
int main() {
	int processes[] = { 1, 2, 3 };
	int n = sizeof(processes) / sizeof(processes[0]);
	int burst_time[] = { 10, 5, 8 };
	calculateAvgTime(processes, n, burst_time);
	return 0;
}
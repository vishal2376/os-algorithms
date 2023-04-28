#include<bits/stdc++.h>
using namespace std;
struct process {
	char name;
	int at, bt, ct, wt, tt, completed;
	float ntt;
} p[10];
int n;
void sortByArrival() {
	struct process temp;
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			if (p[i].at > p[j].at) {
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
}
int main() {
	int i, j, s_bt = 0;
	char c;
	float t, aw = 0, at = 0;
	n = 5;
	int arriv[] = {0, 2, 4, 6, 8};
	int burst[] = {3, 6, 4, 5, 2};
	for (i = 0, c = 'A'; i < n; i++, c++) {
		p[i].name = c;
		p[i].at = arriv[i];
		p[i].bt = burst[i];
		p[i].completed = 0;
		s_bt += p[i].bt;
	}
	sortByArrival();
	cout << "PN\tAT\tBT\tWT\tTAT\tNTT";
	for (t = p[0].at; t < s_bt;) {
		float hrr = -9999, temp; int loc;
		for (i = 0; i < n; i++) {
			if (p[i].at <= t && !p[i].completed) {
				temp = (p[i].bt + (t - p[i].at)) / p[i].bt;
				if (hrr < temp) {
					hrr = temp;
					loc = i;
				}
			}
		}
		t += p[loc].bt;
		p[loc].wt = t - p[loc].at - p[loc].bt;
		p[loc].tt = t - p[loc].at;
		at += p[loc].tt;
		p[loc].ntt = ((float)p[loc].tt / p[loc].bt);
		p[loc].completed = 1;
		aw += p[loc].wt;
		cout << "\n" << p[loc].name << "\t" << p[loc].at;
		cout << "\t" << p[loc].bt << "\t" << p[loc].wt;
		cout << "\t" << p[loc].tt << "\t" << p[loc].ntt;
	}
	cout << "\nAWT: " << aw / n << endl;
	cout << "ATT: " << at / n;
}
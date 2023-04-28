#include <bits/stdc++.h>
using namespace std;
struct P {
	int id;
	int bt;
	int at;
};
void findWaitingTime(P p[], int n, int wt[]) {
	int rt[n];
	for (int i = 0; i < n; i++)
		rt[i] = p[i].bt;
	int complete = 0, t = 0, minm = INT_MAX;
	int shortest = 0, ft;
	bool check = false;
	while (complete != n) {
		for (int j = 0; j < n; j++) {
			if ((p[j].at <= t) && (rt[j] < minm) && rt[j] > 0) {
				minm = rt[j];
				shortest = j;
				check = true;
			}
		}
		if (check == false) {
			t++;
			continue;
		}
		rt[shortest]--;
		minm = rt[shortest];
		if (minm == 0)
			minm = INT_MAX; if (rt[shortest] == 0) {
			complete++;
			check = false;
			ft = t + 1;
			wt[shortest] = ft - p[shortest].bt - p[shortest].at;
			if (wt[shortest] < 0)
				wt[shortest] = 0;
		}
		t++;
	}
}
void findTurnAroundTime(P p[], int n, int wt[], int tat[]) {
	for (int i = 0; i < n; i++)
		tat[i] = p[i].bt + wt[i];
}
void findavgTime(P p[], int n) {
	int wt[n], tat[n], total_wt = 0, total_tat = 0;
	findWaitingTime(p, n, wt);
	findTurnAroundTime(p, n, wt, tat);
	cout << "P\tBT\tWT\tTAT\n";
	for (int i = 0; i < n; i++) {
		total_wt += wt[i];
		total_tat += tat[i];
		cout << p[i].id << "\t" << p[i].bt << "\t" << wt[i] << "\t" << tat[i] << endl;
	}
	cout << "Average waiting time = " << (float)total_wt / (float)n;
	cout << "\nAverage turn around time = " << (float)total_tat / (float)n;
}
int main() {
	P p[] = { { 1, 6, 2 }, { 2, 2, 5 }, { 3, 8, 1 }, { 4, 3, 0}, {5, 4, 4} };
	int n = sizeof(p) / sizeof(p[0]);
	findavgTime(p, n);
	return 0;
}
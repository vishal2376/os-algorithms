#include <iostream>
using namespace std;
int main() {
// Process names
	int num_processes = 5;
	int num_resources = 3;
	int alloc[5][3] = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}}; // Allocation Matrix
	int max[5][3] = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}}; // MAX Matrix
	int avail[3] = {3, 3, 2}; // Available Resources
	int f[num_processes], ans[num_processes], ind = 0;
	for (int k = 0; k < num_processes; k++) {
		f[k] = 0;
	}
	int need[num_processes][num_resources];
	for (int i = 0; i < num_processes; i++) {
		for (int j = 0; j < num_resources; j++)
			need[i][j] = max[i][j] - alloc[i][j];
	}
// Execute Banker's Algorithm
	int y = 0;
	for (int k = 0; k < num_processes; k++) {
		for (int i = 0; i < num_processes; i++) {
			if (f[i] == 0) {
				int flag = 0;
				for (int j = 0; j < num_resources; j++) {
					if (need[i][j] > avail[j]) {
						flag = 1;
						break;
					}
				}
				if (flag == 0) {
					ans[ind++] = i;
					for (y = 0; y < num_resources; y++)
						avail[y] += alloc[i][y];
					f[i] = 1;
				}
			}
		}
	}
// Check if the system is safe
	int flag = 1;
	for (int i = 0; i < num_processes; i++) {
		if (f[i] == 0) {
			flag = 0;
			cout << "The following system is not safe\n";
			break;
		}
	}
// Print safe sequence
	if (flag == 1) {
		cout << "Following is the SAFE Sequence\n";
		for (int i = 0; i < num_processes - 1; i++)
			cout << " P" << ans[i] << " ->";
		cout << " P" << ans[num_processes - 1];
	}
	return 0;
}
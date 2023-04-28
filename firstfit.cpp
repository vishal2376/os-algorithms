#include <iostream>
#include <cstring>
using namespace std;
void first_fit(int block_size[], int m, int process_size[], int n) {
	int allocation[n];
	memset(allocation, -1, sizeof(allocation));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (block_size[j] >= process_size[i]) {
				allocation[i] = j;
				block_size[j] -= process_size[i];
				break;
			}
		}
	}
	cout << "\nProcess No.\tProcess Size\tBlock no.\n";
	for (int i = 0; i < n; i++) {
		cout << " " << i + 1 << "\t\t" << process_size[i] << "\t\t";
		if (allocation[i] != -1)
			cout << allocation[i] + 1;
		else
			cout << "Not Allocated";
		cout << endl;
	}
}
int main() {
	int block_size[] = {100, 500, 200, 300, 600};
	int process_size[] = {212, 417, 112, 426};
	int m = sizeof(block_size) / sizeof(block_size[0]);
	int n = sizeof(process_size) / sizeof(process_size[0]);
	first_fit(block_size, m, process_size, n);
	return 0;
}
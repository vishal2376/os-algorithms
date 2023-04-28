#include <iostream>
#include <algorithm>
using namespace std;
void worstFit(int blockSize[], int m, int processSize[], int n)
{
	int allocation[n];
	fill_n(allocation, n, -1);
// Sort block sizes in descending order
	sort(blockSize, blockSize + m, greater<int>());
	for (int i = 0; i < n; i++) {
		int wstIdx = -1;
		for (int j = 0; j < m; j++) {
			if (blockSize[j] >= processSize[i]) {
				wstIdx = j;
				break;
			}
		}
		if (wstIdx != -1) {
			allocation[i] = wstIdx;
			blockSize[wstIdx] -= processSize[i];
		}
	}
	cout << "\nProcess No.\tProcess Size\tBlock no.\n";
	for (int i = 0; i < n; i++) {
		cout << " " << i + 1 << "\t\t" << processSize[i] << "\t\t";
		if (allocation[i] != -1)
			cout << allocation[i] + 1;
		else
			cout << "Not Allocated";
		cout << endl;
	}
} int main()
{
	int blockSize[] = {100, 500, 200, 300, 600};
	int processSize[] = {212, 417, 112, 426};
	int m = sizeof(blockSize) / sizeof(blockSize[0]);
	int n = sizeof(processSize) / sizeof(processSize[0]);
	worstFit(blockSize, m, processSize, n);
	return 0;
}
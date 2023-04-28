#include<iostream>
using namespace std;

void bestFit(int b[], int m, int p[], int n)
{
	int a[n];
	for (int i = 0; i < n; i++)
		a[i] = -1;
	for (int i = 0; i < n; i++)
	{
		int idx = -1;
		for (int j = 0; j < m; j++)
		{
			if (b[j] >= p[i])
			{
				if (idx == -1)
					idx = j;
				else if (b[idx] > b[j])
					idx = j;
			}
		}
		if (idx != -1)
		{
			a[i] = idx;
			b[idx] -= p[i];
		}
	}
	cout << "\nProcess No.\tProcess Size\tBlock no.\n";
	for (int i = 0; i < n; i++)
	{
		cout << " " << i + 1 << "\t\t" << p[i] << "\t\t";
		if (a[i] != -1)
			cout << a[i] + 1;
		else
			cout << "Not Allocated";
		cout << endl;
	}
}
int main()
{
	int b[] = {100, 500, 200, 300, 600}; int p[] = {212, 417, 112, 426};
	int m = sizeof(b) / sizeof(b[0]);
	int n = sizeof(p) / sizeof(p[0]);
	bestFit(b, m, p, n);
	return 0;
}
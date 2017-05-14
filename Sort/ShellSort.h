#pragma once

void ShellSort(int* a, int n)
{
	assert(a);
	int gap = n / 2 + 1;
	while (gap > 1)
	{
		for (size_t i = 0; i < n - gap; ++i)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
				}
				else
				{
					break;
				}
				end -= gap;
			}
			a[end + gap] = tmp;
		}
		gap = gap / 2 + 1;
	}
	
}

void TestShellSort()
{
	int a[] = { 2, 5, 4, 9, 3, 6, 8, 7, 1, 0 };
	ShellSort(a, sizeof(a) / sizeof(a[0]));
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
#pragma once

void InsertSort(int* a, int n)
{
	assert(a);
	for (int i = 0; i < n - 1; ++i)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

void TestInsertSort()
{
	int a[] = { 2, 5, 4, 9, 3, 6, 8, 7, 1, 0 };
	InsertSort(a, sizeof(a) / sizeof(a[0]));
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
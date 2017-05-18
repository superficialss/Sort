#pragma once

int PartSort1(int* a, int left, int right)
{
	int key = a[right];
	int begin = left;
	int end = right;
	while (begin < end)
	{
		while (begin < end && a[begin] <= key)
		{
			++begin;
		}
		while (begin < end && a[end] >= key)
		{
			--end;
		}
		if (begin < end)
		{
			swap(a[begin], a[end]);
		}
	}
	swap(a[begin], a[right]);
	return begin;
}

void QuitSort(int* a, int left, int right)
{
	assert(a);
	if (left >= right)
	{
		return;
	}
	int div = PartSort1(a, left, right);
	QuitSort(a, left, div - 1);
	QuitSort(a, div + 1, right);
}

void TestQuitSort()
{
	int a[] = { 2, 5, 4, 9, 3, 6, 8, 7, 1, 0 };
	QuitSort(a, 0, sizeof(a) / sizeof(a[0]) - 1);
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
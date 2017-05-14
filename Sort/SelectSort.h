#pragma once

void SelectSort(int* a, size_t n)
{
	int left = 0;
	int right = n - 1;
	while (left < right)
	{
		size_t MinIndex = left;
		size_t MaxIndex = right;
		for (size_t i = left; i <= right; ++i)
		{
			if (a[i] < a[MinIndex])
			{
				MinIndex = i;
			}
			if (a[i] > a[MaxIndex])
			{
				MaxIndex = i;
			}
		}
		swap(a[left], a[MinIndex]);
		if (MaxIndex == left)
		{
			MaxIndex = MinIndex;
		}
		swap(a[right], a[MaxIndex]);
		++left;
		--right;
	}
}

void TestSelectSort()
{
	int a[] = { 2, 5, 4, 9, 3, 6, 8, 7, 1, 0 };
	SelectSort(a, sizeof(a) / sizeof(a[0]));
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
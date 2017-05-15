#pragma once

void BubbleSort(int* a, size_t n)
{
	assert(a);
	for (size_t i = 0; i < n ; ++i)
	{
		for (size_t j = i + 1; j < n  ; ++j)
		{
			if (a[i] > a[j])
			{
				swap(a[i], a[j]);
			}
		}
	}
}

void TestBubbleSort()
{
	int a[] = { 2, 5, 4, 9, 3, 6, 8, 7, 1, 0 };
	BubbleSort(a, sizeof(a) / sizeof(a[0]));
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
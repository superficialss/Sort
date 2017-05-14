#pragma once

void AdjustDown(int* a, size_t n, int root)
{
	int parent = root;
	int child = root * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n &&a[child + 1] > a[child])
		{
			++child;
		}
		if (a[child] > a[parent])
		{
			swap(a[child], a[parent]);
		}
		parent = child;
		child = parent * 2 + 1;
	}
}

void Print(int* a, size_t n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

void HeapSort(int* a, size_t n)
{
	assert(a);
	for (int i = (n - 2) >> 1; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
	Print(a, n);
	for (int i = n - 1 ; i > 0; --i)
	{
		
		swap(a[0], a[i]);
		AdjustDown(a, i, 0);
		Print(a, n);
	}
}

void TestHeapSort()
{
	int a[] = { 2, 5, 4, 9, 3, 6, 8, 7, 1, 0 };
	HeapSort(a, sizeof(a) / sizeof(a[0]));
}

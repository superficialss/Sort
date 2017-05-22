#pragma once

void CountSort(int* a, size_t n)         //¼ÆÊýÅÅÐò
{
	assert(a);
	int max = a[0];
	int min = a[0];
	for (size_t i = 0; i < n; ++i)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
		if (a[i] < min)
		{
			min = a[i];
		}
	}
	int size = max - min + 1;
	int* count = new int[size];
	memset(count, 0, sizeof(int)*size);
	for (size_t i = 0; i < n; ++i)
	{
		count[a[i] - min]++;
	}
	int j = 0;

	for (size_t i = 0; i < n; ++i)
	{
		while (count[i]--)
		{
			a[j++] = i + min;
		}
	}
	delete[] count;
}

void TestCountSort()
{
	int a[] = { 2, 5, 4, 9, 3, 6, 8, 7, 1, 0 };
	CountSort(a, sizeof(a) / sizeof(a[0]));
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

#pragma once

void _MergeSort(int* src, int* dst, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int mid = left + (right - left) >> 1;
	_MergeSort(src, dst, left, mid);
	_MergeSort(src, dst, mid + 1, right);

	int begin1 = left;
	int begin2 = mid + 1;
	int index = 0;
	while (begin1 <= mid && begin2 <= right)
	{
		if (src[begin1] < src[begin2])
		{
			dst[index++] = src[begin1++];
		}
		else
		{
			dst[index++] = src[begin2++];
		}
	}
	while (begin1 <= mid)
	{
		dst[index++] = src[begin1++];
	}
	while (begin2 <= right)
	{
		dst[index++] = src[begin2++];
	}
	int j = 0;
	for (size_t i = 0; i < index; ++i)
	{
		src[j++] = dst[i];
	}
}

void MergeSort(int* a, size_t n)
{
	assert(a);
	int* tmp = new int[n];
	_MergeSort(a, tmp, 0, n - 1);
	delete[] tmp;
}

void TestMergeSort()
{
	int a[] = { 2, 5, 4, 9, 3, 6, 8, 7, 1, 0 };
	MergeSort(a, sizeof(a) / sizeof(a[0]));
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
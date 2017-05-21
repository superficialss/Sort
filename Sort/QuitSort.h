#pragma once
#include"InsertSort.h"

int GetMidIndex(int* a, int left, int right)
{
	assert(a);
	int mid = left + (right - left) >> 1;
	if (a[left] > a[mid])
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if(a[left] < a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else      //a[left] < a[mid]
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left] > a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}

int PartSort1(int* a, int left, int right)  //◊Û”“÷∏’Î∑®
{
	assert(a);
	int mid = GetMidIndex(a, left, right);
	swap(a[mid], a[right]);
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

int PartSort2(int* a, int left, int right)    //Õ⁄ø”∑®
{
	assert(a);
	int mid = GetMidIndex(a, left, right);
	swap(a[mid], a[right]);
	int key = a[right];
	while (left < right)
	{
		while (left < right && a[left] <= key)
		{
			++left;
		}
		a[right] = a[left];
		while (left < right && a[right] >= key)
		{
			--right;
		}
		a[left] = a[right];
	}
	a[left] = key;
	return key;
}

int PartSort3(int* a, int left, int right)
{
	assert(a);
	int mid = GetMidIndex(a, left, right);
	swap(a[mid], a[right]);
	int key = a[right];
	int prev = left - 1;
	int cur = left;
	while (cur < right)
	{
		if (a[cur] < key && ++prev != cur)
		{
			swap(a[prev], a[cur]);
		}
		++cur;
	}
	swap(a[++prev], a[right]);
	return prev;
}

void QuitSort(int* a, int left, int right)
{
	assert(a);
	if (left >= right)
	{
		return;
	}
	if (right - left < 5)
	{
		InsertSort(a + left, right - left + 1);
	}
	else
	{
		int div = PartSort3(a, left, right);
		//int div = PartSort2(a, left, right);
		//int div = PartSort1(a, left, right);
		QuitSort(a, left, div - 1);
		QuitSort(a, div + 1, right);
	}
}

void QuitSortNonR(int* a, int left, int right)
{
	assert(a);
	stack<int> s;
	s.push(right);
	s.push(left);
	while (!s.empty())
	{
		int begin = s.top();
		s.pop();
		int end = s.top();
		s.pop();
		if (end - begin < 5)
		{
			InsertSort(a + begin, end - begin + 1);
		}
		else
		{
			int div = PartSort3(a, left, right);
			if (div - 1 > begin)
			{
				s.push(div - 1);
				s.push(begin);
			}
			if (div + 1 < end)
			{
				s.push(end);
				s.push(div + 1);
			}
		}
	}
}

void TestQuitSort()
{
	int a[] = { 2, 5, 4, 9, 3, 6, 8, 7, 1, 0 };
	//QuitSort(a, 0, sizeof(a) / sizeof(a[0]) - 1);
	QuitSortNonR(a, 0, sizeof(a) / sizeof(a[0]) - 1);
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
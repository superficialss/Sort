#pragma once

template<typename T>
struct Less
{
	bool operator()(const T& l, const T& r) const
	{
		return l < r;
	}
};

template<typename T>
struct Greater
{
	bool operator()(const T& l, const T& r) const
	{
		return l > r;
	}
};

template<typename T, typename Compare = Less<T>>
void InsertSort(T* a, T n)
{
	Compare ComFunc;
	assert(a);
	for (int i = 0; i < n - 1; ++i)
	{
		int end = i;
		T tmp = a[end + 1];
		while (end >= 0)
		{
			//if (a[end] > tmp)
			if(ComFunc(tmp, a[end]))
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
	InsertSort<int>(a, sizeof(a) / sizeof(a[0]));
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
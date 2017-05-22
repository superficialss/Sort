#pragma once          //基数排序

int GetDigit(int* a, size_t n)
{
	int digit = 1;
	int base = 10;
	for (size_t i = 0; i < n; ++i)
	{
		while (a[i] >= base)
		{
			++digit;
			base *= 10;
		}
	}
	return digit;
}

void LSD(int* a, size_t n) //低位向高位排
{
	assert(a);
	int digit = GetDigit(a, n);
	int base = 1;
	int* buket = new int[n];
	for (size_t j = 0; j < digit; ++j)
	{
		int count[10] = { 0 };
		int start[10] = { 0 };
		for (size_t i = 0; i < n; ++i)
		{
			int num = (a[i] / base) % 10;
			count[num]++;
		}
		for (size_t i = 1; i < 10; ++i)
		{
			start[i] = start[i - 1] + count[i - 1];
		}
		for (size_t i = 0; i < n; ++i)
		{
			int num = a[i]/ base % 10;
			buket[start[num]++] = a[i];
		}
		for (size_t i = 0; i < n; ++i)
		{
			a[i] = buket[i];
		}
		base *= 10;
	}	
}

void TestLSD()
{
	int a[] = { 2, 5, 4, 9, 3, 6, 8, 7, 1, 0 };
	LSD(a, sizeof(a) / sizeof(a[0]));
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
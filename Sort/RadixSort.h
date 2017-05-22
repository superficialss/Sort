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

}
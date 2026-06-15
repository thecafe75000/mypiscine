/*
Assignment name  : max
Expected files   : max.c
Allowed functions:
--------------------------------------------------------------------------------
Write the following function:
int	max(int* tab, unsigned int len);

The first parameter is an array of int, the second is the number of elements in
the array.
The function returns the largest number found in the array.
If the array is empty, the function returns 0.

	max函数接收一个整数数组 tab 和数组长度 len，返回数组中的最大值
	要求：
		如果 len == 0，返回 0
		否则遍历数组，找出并返回最大的整数
		如果数组里全是负数，也要返回其中最大的那个负数，不是返回 0
*/

int max(int *tab, unsigned int len)
{
	unsigned i;
	int max;

	i = 0;
	max = tab[0];
	if (len == 0)
		return (0);
	while (i < len)
	{
		if (max < tab[i])
			max = tab[i];
		i++;
	}
	return (max);
}

#include <stdio.h>

int main()
{
	int arr[] = {-3, -9, 0, -6, 18, 3, 9};
	printf("max = %d\n", max(arr, 7));

	return (0);
}

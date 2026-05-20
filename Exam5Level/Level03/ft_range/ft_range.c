/*
Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------
Write the following function:
int			*ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:
- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.
*/
/*
	动态分配一个 int 数组，并把从 start 到 end 的所有连续整数放进去，包含 start 和 end 本身。

	重点要求：
		只能提交文件：ft_range.c
		只能使用函数：malloc
		返回值是数组第一个元素的地址，也就是 int *
		如果 start <= end，数组递增
		如果 start > end，数组递减
		数组长度是 start 到 end 之间整数的个数，包含两端

	核心思路：
		数组长度 = start 和 end 的差值的绝对值 + 1
	然后：
		用 malloc 分配这么多个 int
		从 start 开始填
		如果 start < end，每次加 1
		如果 start > end，每次减 1
		返回数组地址
*/

// 注意这题和ft_rrange不同的地方在于返回的数组的元素顺序和ft_rrange是相反的
#include <stdlib.h>

static int	get_len(int start, int end)
{
	int	len;

	if (start > end)
	{
		len = start - end + 1;
	}
	else
	{
		len = end - start + 1;
	}
	return (len);
}

int	*ft_range(int start, int end)
{
	int	*rangep;
	int	len;
	int	i;

	len = get_len(start, end);
	rangep = (int *)malloc(sizeof(int) * len);
	if (rangep == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		rangep[i] = start;
		if (start < end)
			start += 1;
		else
			start -= 1;
		i++;
	}
	return (rangep);
}

#include <stdio.h>

int	main(void)
{
	int	i;
	int	*arr1;
	int	j;
	int	*arr2;
	int	k;
	int	*arr3;
	int m;
	int *arr4;
	int length1;
	int	length2;
	int	length3;
	int	length4;

	length1 = get_len(1, 3);
	length2 = get_len(-1, 2);
	length3 = get_len(0, 0);
	length4 = get_len(0, -3);
	i = 0;
	arr1 = ft_range(1, 3);
	while (i < length1)
	{
		printf("%d ", arr1[i]);
		i++;
	}
	free(arr1);
	printf("\n\n");
	j = 0;
	arr2 = ft_range(-1, 2);
	while (j < length2)
	{
		printf("%d ", arr2[j]);
		j++;
	}
	free(arr2);
	printf("\n\n");
	k = 0;
	arr3 = ft_range(0, 0);
	while (k < length3)
	{
		printf("%d ", arr3[k]);
		k++;
	}
	free(arr3);
	printf("\n\n");
	m = 0;
	arr4 = ft_range(0, -3);
	while (m < length4)
	{
		printf("%d ", arr4[m]);
		m++;
	}
	free(arr4);
	printf("\n");
	return (0);
}

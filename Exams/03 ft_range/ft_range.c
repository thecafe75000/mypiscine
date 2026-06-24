/*
Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------
Write the following function:
int	*ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:
- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.

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

	注意这题和ft_rrange不同的地方在于返回的数组的元素顺序和ft_rrange是相反的

*/

#include <stdlib.h>

int	get_length(int start, int end)
{
	int	len;

	len = 0;
	if (start > end)
		len = start - end + 1;
	else
		len = end - start + 1;
	return (len);
}

int	get_step(int start, int end)
{
	int	step;

	if (start > end)
		step = -1;
	else
		step = 1;
	return (step);
}

int	*ft_range(int start, int end)
{
	int	len;
	int	*result;
	int	i;
	int step;

	len = get_length(start, end);
	result = malloc(sizeof(int) * len);
	if (!result)
		return (NULL);
	i = 0;
	step = get_step(start, end);
	while (i < len)
	{
		result[i] = start;
		start += step;
		i++;
	}
	return (result);
}

#include <stdio.h>

int	main(void)
{
	int	x;
	int	y;
	int	*result;
	int	len;
	int	i;

	x = 0;
	y = -3;
	result = ft_range(x, y);
	len = get_length(x, y);
	i = 0;
	while (i < len)
	{
		printf("%d ", result[i]);
		i++;
	}
	return (0);
}

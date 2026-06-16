/*
Assignment name  : ft_rrange
Expected files   : ft_rrange.c
Allowed functions: malloc
--------------------------------------------------------------------------------
Write the following function:
int	*ft_rrange(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at end and end at start (Including start and end !), then
return a pointer to the first value of the array.

Examples:
- With (1, 3) you will return an array containing 3, 2 and 1
- With (-1, 2) you will return an array containing 2, 1, 0 and -1.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing -3, -2, -1 and 0.

	动态申请一个 int 数组，把从 end 到 start 的所有整数按顺序放进去，然后返回这个数组的地址
	注意：不是从 start 到 end，而是反过来，从 end 开始，到 start 结束

	核心逻辑是：
		先算出需要几个整数；
		用 malloc(sizeof(int) * len) 申请内存；
		从 end 开始填；
		如果 end > start, 数值从 end 往下走, 每次减 1；
		如果 end < start, 数值从 end 往上走, 每次加 1；
		如果 end == start，数组里只有一个数
		最后返回数组
	注意2点：
		当前值：end
		下一步： end += step;
		step决定了end往上走(+1)还是往下走(-1)
	举例：
		start = 5, end = 2, 数组应该是[2, 3, 4, 5], step 必须 +1
		start = 2, end = 5, 数组应该是[5, 4, 3, 2], step 必须 -1
*/

#include <stdlib.h>

int	get_length(int start, int end)
{
	int	len;

	if (start > end)
		len = start - end + 1;
	else
		len = end - start + 1;
	return (len);
}

// 决定“填充数组时 end 每次是递增还是递减”
int get_step(int start, int end)
{
	int step;

	if(start > end)
		step = 1;
	else
		step = -1;
	return (step);
}

int	*ft_rrange(int start, int end)
{
	int len;
	int *result;
	int step;
	int i;

	len = get_length(start, end);
	result = malloc(sizeof(int) * (len + 1));
	if (!result)
		return (NULL);
	step = get_step(start, end);
	i = 0;
	while (i < len)
	{
		result[i] = end;
		end += step;
		i++;
	}
	return (result);
}

#include <stdio.h>

int main()
{
	int start = 0;
	int end = -3;
	int len = get_length(start, end);
	int *arr = ft_rrange(start, end);
	if (!arr)
		return (1);
	int i = 0;
	while (i < len)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
	free(arr);
	return (0);
}

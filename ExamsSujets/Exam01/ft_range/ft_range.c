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

动态分配一个 int 数组，并把从 start 到 end 的所有连续整数放进去，包含 start 和 end 本身
核心思路：
		数组长度 = start 和 end 的差值的绝对值 + 1
	然后：
		用 malloc 动态分配这么多个 int
		从 start 开始填
		如果 start < end，每次加 1
		如果 start > end，每次减 1
		返回数组地址
*/

#include <stdlib.h>

int get_length(int start, int end)
{
	if (start > end)
		return (start - end + 1);
	return (end - start + 1);
}

int	*ft_range(int start, int end)
{
	int len;
	int *range;
	int i;

	len = get_length(start, end);
	range = malloc(sizeof(int) * len);
	if (!range)
		return (NULL);
	i = 0;
	while (i < len)
	{
		range[i] = start;
		if (start < end)
			start++;
		else
			start--;
		i++;
	}
	return (range);
}

#include <stdio.h>

int main()
{
	int len = get_length(0, -3);
	int *range = ft_range(0, -3);
	int i = 0;
	while (i < len)
	{
		printf("%d ", range[i]);
		i++;
	}
	free(range);
	printf("\n");
}

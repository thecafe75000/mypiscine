/*
Assignment name  : ft_rrange
Expected files   : ft_rrange.c
Allowed functions: malloc
--------------------------------------------------------------------------------
Write the following function:
int			*ft_rrange(int start, int end);
It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at end and end at start (Including start and end !), then
return a pointer to the first value of the array.

Examples:
- With (1, 3) you will return an array containing 3, 2 and 1
- With (-1, 2) you will return an array containing 2, 1, 0 and -1.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing -3, -2, -1 and 0.

详细解释从0到最后完成这题的每个解题步骤, 同时解释为什么这么构思
*/
/*
	动态申请一个 int 数组，把从 end 到 start 的所有整数按顺序放进去，然后返回这个数组的地址
	注意：不是从 start 到 end，而是反过来，从 end 开始，到 start 结束

	核心逻辑是：
		先算出需要几个整数；
		用 malloc(sizeof(int) * len) 申请内存；
		从 end 开始填；
		如果 end > start, 从 end 往下走, 每次减 1；
		如果 end < start, 从 end 往上走, 每次加 1；
		如果 end == start，数组里只有一个数
		最后返回数组
*/

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

static int	get_step(int start, int end)
{
	int	step;

	if (start > end)
	{
		step = 1;
	}
	else
	{
		step = -1;
	}
	return (step);
}

int	*ft_rrange(int start, int end)
{
	int	*rangep;
	int	len;
	int	i;
	int	step;

	len = get_len(start, end);
	rangep = (int *)malloc(sizeof(int) * len);
	if (rangep == NULL)
		return (NULL);
	i = 0;
	step = get_step(start, end);
	while (i < len)
	{
		rangep[i] = end;
		end += step;
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
	int	length1;
	int	length2;
	int	length3;

	length1 = get_len(0, -3);
	length2 = get_len(-1, 2);
	length3 = get_len(0, 0);
	i = 0;
	arr1 = ft_rrange(0, -3);
	while (i < length1)
	{
		printf("%d ", arr1[i]);
		i++;
	}
	free(arr1);
	printf("\n\n");
	j = 0;
	arr2 = ft_rrange(-1, 2);
	while (j < length2)
	{
		printf("%d ", arr2[j]);
		j++;
	}
	free(arr2);
	printf("\n\n");
	k = 0;
	arr3 = ft_rrange(0, 0);
	while (k < length3)
	{
		printf("%d ", arr3[k]);
		k++;
	}
	free(arr3);
	printf("\n");
	return (0);
}

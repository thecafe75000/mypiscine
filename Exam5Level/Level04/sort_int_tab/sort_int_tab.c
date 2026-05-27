/*
Assignment name  : sort_int_tab
Expected files   : sort_int_tab.c
Allowed functions:
--------------------------------------------------------------------------------
Write the following function:
void	sort_int_tab(int *tab, unsigned int size);

It must sort (in-place) the 'tab' int array, that contains exactly 'size'
members, in ascending order.
Doubles must be preserved.
Input is always coherent.

*/
/*
	写一个函数，用来把一个 int 数组原地升序排序
	核心就是：比较数组里的数字，如果前面的比后面的大，就交换，最后整个数组变成升序

	参数tab 是一个整数数组
	参数size 是数组元素个数
	要把数组按从小到大排序
	必须直接修改原数组，也就是 in-place
	相同的数字不能删掉，题目里的 Doubles must be preserved 指的是重复值要保留
	Input is always coherent 表示输入总是合理的，不用处理奇怪情况，比如 tab == NULL 之类

	举例：
	int tab[] = {5, 2, 9, 2, 1};
	sort_int_tab(tab, 5);
	排序后数组应该变成：
		{1, 2, 2, 5, 9}

	可以用冒泡排序实现
*/

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	int				temp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
}

#include <stdio.h>

int	main(void)
{
	int	i;
	int	tab[] = {-1, -6, 9, 2, 6, 2, 18, 17};

	i = 0;
	sort_int_tab(tab, 8);
	while (i < 8)
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n");
	return (0);
}

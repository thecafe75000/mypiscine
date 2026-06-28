/*
Assignment name  : count_alpha
Expected files   : count_alpha.c
Allowed functions: write, printf
--------------------------------------------------------------------------------
Write a Count_alpha program that takes a chain and displays the number of occurrences
of its alphabetical characters.The other characters are not counted.Order is the order of appearance in the chain.
The display must be finished with a Newline.

The format is in examples.

If the number of arguments is not 1, just display a newline.

Exemples :
$> ./count_alpha abbcc
1a, 2b, 2c
$> ./count_alpha "abbcc"
1a, 2b, 2c
$> ./count_alpha "abbcc" "dddeef" | cat -e
$
$> ./count_alpha "My Hyze 47y 7." | cat -e
1m, 3y, 1h, 1z, 1e$
$> ./count_alpha "" | cat -e
$

	统计字符串中每个字母第一次出现时，它在整个字符串中总共出现了多少次。
	也就是遇到一个字母时，如果这是它第一次出现，就统计它在整个字符串里一共出现了多少次，然后输出

	注意几点：
		只统计字母（a-z、A-Z）
		大小写不区分（统一按小写输出）
		非字母字符忽略
		输出顺序按照字母第一次出现的顺序
		同一个字母只输出一次
		格式为：次数 + 字母
		多个结果之间用：", " 分隔
		最后输出换行符 \n

	算法：
	遍历字符串，是不是字母？
		- 否：则跳过
		- 是：则继续看是否是第1次出现？
			- 否：则跳过
			- 是：统计总次数，然后输出
	即：
	第一次出现 → 统计总次数 → 输出
	不是第一次出现 → 跳过

*/

#include <stdio.h>

char	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

// 判断 str[pos] 在前面有没有出现
int	already_showed(char *str, int pos)
{
	int	i;

	i = 0;
	while (i < pos)
	{
		if (to_lower(str[i]) == to_lower(str[pos]))
			return (1);
		i++;
	}
	return (0);
}

// 统计字母出现的次数
int	count_showed(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (to_lower(str[i]) == to_lower(c))
			count++;
		i++;
	}
	return (count);
}

int	main(int argc, char **argv)
{
	int	i;
	int	count;
	int	first;

	if (argc != 2)
	{
		printf("\n");
		return (0);
	}
	i = 0;
	first = 1;
	while (argv[1][i])
	{
		if ((argv[1][i] >= 'a' && argv[1][i] <= 'z') || (argv[1][i] >= 'A' && argv[1][i] <= 'Z'))
		{
			if (!already_showed(argv[1], i))
			{
				count = count_showed(argv[1], argv[1][i]);
				if (!first) // 如果不是第一个输出
					printf(", ");
				printf("%d%c", count, to_lower(argv[1][i]));
				first = 0;
			}
		}
		i++;
	}
	printf("\n");
	return (0);
}

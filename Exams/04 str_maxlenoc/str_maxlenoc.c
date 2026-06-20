/*
Assignment name  : str_maxlenoc
Expected files   : str_maxlenoc.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------
Write a program that takes n strings as parameters and displays,
followed by a newline, the longest string of characters included
in all the parameters passed. If several strings correspond,
the one that appears first in the first parameter will be displayed.
Note that "" is necessarily in all strings.

If no parameter is transmitted, the program should display '\n'.

Let A and B be strings of characters. We say that A is included
in B if A is a substring of B or if A and B are identical.

Examples:
$>./str_maxlenoc ab bac abacabccabcb
a
$>./str_maxlenoc bonjour salut bonjour bonjour
u
$>./str_maxlenoc xoxAoxo xoxAox  oxAox oxo  A ooxAoxx oxooxo Axo | cat -e
$
$>./str_maxlenoc bosdsdfnjodur atehhellosd afkuonjosurafg headfgllosf fghellosag afdfbosnjourafg
os
$>./str_maxlenoc | cat -e
$

	在所有字符串中找最长的“连续子串”，它必须同时出现在每一个字符串里

	标准做法是：
	从第一个字符串出发，枚举所有可能子串，再验证它是否存在于所有字符串中
	这题不能“从多字符串同时找”，因为太复杂
	所有答案 一定来自 S1，因为最终答案必须出现在所有字符串里，也必然出现在 S1
	所以我们只在 S1 里“造候选字符串”
*/

#include <unistd.h>

/* ---------------- strlen ---------------- */
int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/* ---------------- check substring ---------------- */
/* 判断 s2 是否出现在 s1 中 */
int	contains(char *s1, char *s2, int len2)
{
	int	i;
	int	j;

	i = 0;
	if (len2 == 0)
		return (1);
	while (s1[i])
	{
		j = 0;
		while (s1[i + j] && s2[j] && s1[i + j] == s2[j] && j < len2)
			j++;
		if (j == len2)
			return (1);
		i++;
	}
	return (0);
}

/* ---------------- check all strings ---------------- */
int	in_all(char **av, int ac, char *s1, int start, int len)
{
	int	i;

	i = 2;
	while (i < ac)
	{
		if (!contains(av[i], s1 + start, len))
			return (0);
		i++;
	}
	return (1);
}

/* ---------------- write substring ---------------- */
void	print_sub(char *s, int start, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		write(1, &s[start + i], 1);
		i++;
	}
}


int	main(int ac, char **av)
{
	int i;
	int j;
	int len;
	int best_len = 0;
	int best_start = 0;

	if (ac < 2)
	{
		write(1, "\n", 1);
		return (0);
	}

	len = ft_strlen(av[1]);

	i = 0;
	while (i < len)
	{
		j = i;
		while (j < len)
		{
			int cur_len = j - i + 1;

			if (cur_len > best_len)
			{
				if (in_all(av, ac, av[1], i, cur_len))
				{
					best_len = cur_len;
					best_start = i;
				}
			}
			j++;
		}
		i++;
	}

	if (best_len > 0)
		print_sub(av[1], best_start, best_len);

	write(1, "\n", 1);
	return (0);
}

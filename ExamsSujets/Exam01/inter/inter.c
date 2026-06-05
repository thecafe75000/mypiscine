/*
Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.
The display will be followed by a \n.
If the number of arguments is not 2, the program displays \n.

Examples:
$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "rien" "cette phrase ne cache rien" | cat -e
rien$
$>./inter | cat -e
$

	写一个 C 程序 inter.c，程序接收 两个字符串参数,
	找出同时出现在两个字符串中的字符,
	并且按它们在第一个字符串中出现的顺序输出,
	每个字符只输出一次。最后输出一个换行符 \n,
	如果参数数量不是 2 个字符串，就只输出一个换行符
	
	因此要求是输出两个字符串中都出现的字符，顺序按照第一个字符串中的出现顺序

	当前字符 argv[1][i] 只有在满足以下条件时输出：
		1. 它在 argv[2] 中；
		2. 它在 argv[1] 的 0 ~ i - 1 范围内没有出现过
*/

#include <unistd.h>

// 字符是否出现在字符串里
int	is_in_string(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}
// 当前字符是否输出过
int	is_already_show(char *str, char c, int pos)
{
	int	i;

	i = 0;
	while (i < pos)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 3)
	{
		i = 0;
		while (argv[1][i])
		{
			if (is_in_string(argv[2], argv[1][i]) && !is_already_show(argv[1],
					argv[1][i], i))
				write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

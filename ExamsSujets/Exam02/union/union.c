/*
Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.
The display will be in the order characters appear in the command line, and
will be followed by a \n.
If the number of arguments is not 2, the program displays \n.

Example:
$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>
	第二个字符串里的字符要满足两个条件才能输出：
		它没有在第一个字符串出现过
		它没有在第二个字符串当前字符之前出现过
*/

#include <unistd.h>

// 判断当前字符是否已经输出过
// pos表示当前字符在字符串里的下标位置,即检查的范围是当前字符之前的所有字符
int	alreay_seen(char *str, char c, int pos)
{
	int i;

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
	int i;
	int j;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (argv[1][i])
	{
		if (!alreay_seen(argv[1], argv[1][i], i))
			write(1, &argv[1][i], 1);
		i++;
	}
	j = 0;
	while (argv[2][j])
	{
		if (!alreay_seen(argv[1], argv[2][j], i) && !alreay_seen(argv[2], argv[2][j], j))
			write(1, &argv[2][j], 1);
		j++;
	}

	write(1, "\n", 1);
	return (0);
}

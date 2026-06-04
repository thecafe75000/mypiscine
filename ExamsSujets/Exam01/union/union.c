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
	把两个字符串中出现过的字符合并输出，但每个字符只能输出一次，
	而且顺序必须按命令行中从左到右第一次出现的顺序
	union 不是逐位比较两个字符串，而是按顺序输出两个字符串中第一次出现的字符

	逻辑是：
		1.如果 argc != 3，输出 \n
		2.如果 argc == 3：
			先遍历 argv[1]
			再遍历 argv[2]
			每遇到一个还没出现过的字符，就用 write 输出
			已经出现过的字符跳过
		3.最后输出 \n

	核心思路是：
		先看第一个字符串，第一个字符串中，某个字符第一次出现，就输出
		再看第二个字符串
		第二个字符串中，某个字符如果在第一个字符串没出现过，并且在第二个字符串前面也没出现过，就输出。
		最后输出 \n
	代码落实：
		第1步：写一个函数，判断字符之前有没有出现过
		第2步：处理main函数的参数数量
		第3步：遍历第一个字符串

*/

#include <unistd.h>

// 参数limit的意思：只检查字符串 str 从下标 0 到下标 limit - 1 的范围
int	already_seen(char *str, char c, int limit)
{
	int	i;

	i = 0;
	while (i < limit)
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
	int	j;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (argv[1][i])
	{
		if (!already_seen(argv[1], argv[1][i], i))
			write(1, &argv[1][i], 1);
		i++;
	}
	j = 0;
	while (argv[2][j])
	{
		if (!already_seen(argv[1], argv[2][j], i) && !already_seen(argv[2], argv[2][j], j))
			write(1, &argv[2][j], 1);
		j++;
	}
	write(1, "\n", 1);
	return (0);
}

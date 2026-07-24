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
		即第二个字符串里的字符要满足两个条件才能输出：
			它没有在第一个字符串出现过
			它没有在第二个字符串当前字符之前出现过
		最后输出 \n
	代码落实：
		第1步：写一个函数，判断字符之前有没有出现过
		第2步：处理main函数的参数数量
		第3步：遍历第一个字符串

	这题和inter题的区别是：
		inter = 共同拥有的字符（交集）
		union = 所有出现过的字符（并集）
	实际上这两个题的代码结构有 80% 是一样的，区别只在于输出条件：
		inter: 在 s2 中找到才输出
		union: 只要以前没出现过就输出

*/

#include <unistd.h>

// 参数pos的意思：只检查字符串 str 从下标 0 到下标 pos - 1 的范围
int	is_showed(char c, char *str, int pos)
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
	int	j;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (argv[1][i])
	{
		if (!is_showed(argv[1][i], argv[1], i))
			write(1, &argv[1][i], 1);
		i++;
	}
	j = 0;
	while (argv[2][j])
	{
		if (!is_showed(argv[2][j], argv[1], i) && !is_showed(argv[2][j], argv[2], j))
			write(1, &argv[2][j], 1);
		j++;
	}
	write(1, "\n", 1);
	return (0);
}

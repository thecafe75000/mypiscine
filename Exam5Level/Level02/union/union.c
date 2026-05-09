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
*/
/*
	把两个字符串中出现过的字符合并输出，但每个字符只能输出一次，
	而且顺序必须按命令行中从左到右第一次出现的顺序

	逻辑是：
		1.如果 argc != 3，输出 \n
		2.如果 argc == 3：
			先遍历 argv[1]
			再遍历 argv[2]
			每遇到一个还没出现过的字符，就用 write 输出
			已经出现过的字符跳过
		3.最后输出 \n
*/

#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
	}
	write(1, "\n", 1);
	return (0);
}

/*
Assignment name  : rev_wstr
Expected files   : rev_wstr.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------
Write a program that takes a string as a parameter, and prints its words in
reverse order.
A "word" is a part of the string bounded by spaces and/or tabs, or the
begin/end of the string.
If the number of parameters is different from 1, the program will display '\n'.
In the parameters that are going to be tested, there won't be any "additional"
spaces (meaning that there won't be additionnal spaces at the beginning or at
the end of the string, and words will always be separated by exactly one space).

Examples:
$> ./rev_wstr "le temps du mepris precede celui de l'indifference" | cat -e
l'indifference de celui precede mepris du temps le$
$> ./rev_wstr "abcdefghijklm"
abcdefghijklm
$> ./rev_wstr "il contempla le mont" | cat -e
mont le contempla il$
$> ./rev_wstr | cat -e
$
$>
*/
/*
	写一个程序接收一个字符串参数，然后把这个字符串里的单词顺序反过来输出
	注意：是反转“单词顺序”，不是反转每个单词本身
	从字符串尾部往前找单词，但每个单词仍然从左到右输出

	注意：
	单词之间只有一个空格
	最前面不能有空格
	最后面不能有空格

	变量is_printed的作用：
		控制单词之间是否打印空格，避免开头多打印一个空格
*/

#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	start;
	int	end;
	int is_printed; // 是否已经打印过单词

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i])
			i++;
		i--;
		is_printed = 0; // 目前还没有打印任何单词
		while (i >= 0)
		{
			while (i >= 0 && (argv[1][i] == ' ' || argv[1][i] == '\t'))
				i--;
			end = i;
			while (i >= 0 && (argv[1][i] != ' ' && argv[1][i] != '\t'))
				i--;
			start = i + 1;
			if (end >= 0)
			{
				if (is_printed)
					write(1, " ", 1);
				while (start <= end)
				{
					write(1, &argv[1][start], 1);
					start++;
				}
				is_printed = 1;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}

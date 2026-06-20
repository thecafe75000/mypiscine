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
*/

#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	start;
	int	end;
	int	first;

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i])
			i++;
		i--;
		first = 1;
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
				if (!first)
					write(1, " ", 1);
				while (start <= end)
				{
					write(1, &argv[1][start], 1);
					start++;
				}
				first = 0;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}

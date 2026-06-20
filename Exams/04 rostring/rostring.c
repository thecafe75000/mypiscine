/*
Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------
Write a program that takes a string and displays this string after rotating it
one word to the left.
Thus, the first word becomes the last, and others stay in the same order.
A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.
Words will be separated by only one space in the output.
If there's less than one argument, the program displays \n.

Example:
$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring | cat -e
$
$>
*/
/*
	程序接收命令行参数中的第一个字符串 argv[1]，“把字符串按单词向左旋转一位”
	即把这个字符串里的第一个单词移动到最后，其他单词保持原来的顺序，然后输出
	也就是第一个单词移动到最后，其他单词顺序不变, 意思是：
		原字符串: word1 word2 word3 word4
		输出:     word2 word3 word4 word1
	注意逗号 , 也算一个单词，因为它不是空格或 tab
	输出时，单词和单词之间只能有一个空格

	核心逻辑是：
		跳过开头空格和 tab
		记录第一个单词的起点 first_start 和终点 first_end
		从第二个单词开始，一个一个输出
		最后再输出第一个单词
		用 printed 控制单词之间只输出一个空格
*/

#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	char	*str;
	int		i;
	int		start;
	int		first_start;
	int		first_end;
	int		printed;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	str = argv[1];
	i = 0;
	printed = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	first_start = i;
	while (str[i] && str[i] != ' ' && str[i] != '\t')
		i++;
	first_end = i;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		start = i;
		while (str[i] && str[i] != ' ' && str[i] != '\t')
			i++;
		if (start < i)
		{
			if (printed)
				write(1, " ", 1);
			while (start < i)
			{
				write(1, &str[start], 1);
				start++;
			}
			printed = 1;
		}
	}
	if (first_start < first_end)
	{
		if (printed)
			write(1, " ", 1);
		while (first_start < first_end)
		{
			write(1, &str[first_start], 1);
			first_start++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

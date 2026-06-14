/*
Assignment name  : first_word
Expected files   : first_word.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a program that takes a string and displays its first word, followed by a
newline.
A word is a section of string delimited by spaces/tabs or by the start/end of
the string.
If the number of parameters is not 1, or if there are no words, simply display
a newline.

Examples:
$> ./first_word "FOR PONY" | cat -e
FOR$
$> ./first_word "this        ...       is sparta, then again, maybe    not" | cat -e
this$
$> ./first_word "   " | cat -e
$
$> ./first_word "a" "b" | cat -e
$
$> ./first_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>
	算法：
		如果 argc == 2，目标字符串是 argv[1]。
		先从字符串开头跳过所有空格 ' ' 和 tab '\t'。
		跳过后的位置如果是 '\0'，说明字符串里没有单词，比如 " "，后面不会输出字符。
		如果当前位置不是字符串结尾，也不是空格和tab，就说明进入了第一个 word。
		持续用 write 一个字符一个字符输出，直到遇到空格、tab 或字符串结尾。
		无论有没有输出单词，最后都输出一个换行。

*/

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (argv[1][i] == ' ' || argv[1][i] == '\t')
		i++;
	while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
	{
		write(1, &argv[1][i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}

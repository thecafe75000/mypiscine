/*
Assignment name  : last_word
Expected files   : last_word.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a program that takes a string and displays its last word followed by a \n.
A word is a section of string delimited by spaces/tabs or by the start/end of
the string.
If the number of parameters is not 1, or there are no words, display a newline.

Example:
$> ./last_word "FOR PONY" | cat -e
PONY$
$> ./last_word "this        ...       is sparta, then again, maybe    not" | cat
	-e
not$
$> ./last_word "   " | cat -e
$
$> ./last_word "a" "b" | cat -e
$
$> ./last_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>

	这题核心是从字符串末尾跳过空格/Tab，再倒着找到最后一个单词的开头，最后正向输出

	正确思路是：
		先走到字符串结尾
		从后往前跳过空格和 tab
		记录最后一个单词的结尾 end
		继续往前找到这个单词的开头
		从开头到结尾正向 write 输出
*/

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	end; // 最后一个单词的结尾

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i])
			i++;
		// 找到最后一个单词的结尾位置
		while (i > 0 && (argv[1][i -1] == ' ' || argv[1][i -1] == '\t'))
			i--;
		end = i;
		// 找到最后一个单词的开头位置
		while (i > 0 && (argv[1][i -1] != ' ' && argv[1][i-1] != '\t'))
			i--;
		while (i < end)
		{
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

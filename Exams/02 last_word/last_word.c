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
	如果程序刚好收到 1 个参数，就从这个字符串里找出最后一个单词，
	并输出这个最后一个单词，最后再输出一个换行符 \n
	一个单词是字符串中一段连续的非空格、非tab字符
	单词的边界可以是：
		空格 ' '
		tab '\t'
		字符串开头
		字符串结尾
	注意事项：
		当命令行参数是2个以上，只输出换行
		当参数是空格或tab，没有任何单词，只输出换行
		当参数是一个单词，则输出该单词自己
	解题思路：
		因为题目只要求最后一个单词，那么可以从字符串末尾开始往前找最后一个单词
	算法：
		先找到字符串结尾
		跳过末尾空格和 tab
		记录最后一个单词的结束位置 end = i;
		往前找到最后一个单词的开始位置
		从开始位置输出到结束位置
		最后输出换行
*/

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;

	int end; // 最后一个单词的结尾
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (argv[1][i])
		i++;
	// 找到最后一个单词的结尾位置
	while (i > 0 && (argv[1][i - 1] == ' ' || argv[1][i - 1] == '\t'))
		i--;
	end = i;
	// 找到最后一个单词的开头位置
	while (i > 0 && argv[1][i - 1] != ' ' && argv[1][i - 1] != '\t')
		i--;
	while (i < end)
	{
		write(1, &argv[1][i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}

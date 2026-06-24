/*
Assignment name  : epur_str
Expected files   : epur_str.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a program that takes a string, and displays this string with exactly one
space between words, with no spaces or tabs either at the beginning or the end,
followed by a \n.
A "word" is defined as a part of a string delimited either by spaces/tabs,
	or by the start/end of the string.
If the number of arguments is not 1, or if there are no words to display,
	the program displays \n.

Example:
$> ./epur_str "vous voyez c'est facile d'afficher la meme chose" | cat -e
vous voyez c'est facile d'afficher la meme chose$
$> ./epur_str " seulement          la c'est      plus dur " | cat -e
seulement la c'est plus dur$
$> ./epur_str "comme c'est cocasse" "vous avez entendu, Mathilde ?" | cat -e
$
$> ./epur_str "" | cat -e
$
$>

	程序接收命令行参数里的一个字符串，然后把这个字符串“清理空白”后输出
	具体要求：
		程序必须只接受 1 个参数
		字符串开头和结尾的空格或 tab 要去掉
		单词之间无论原来有多少个空格或 tab，输出时都变成 正好一个空格
		如果字符串里没有任何单词, 都只输出一个换行
	最稳定的做法是：
		跳过开头空白
		输出一个单词
		跳过单词后的所有空白
		如果后面还有单词，就输出一个空格
		重复直到字符串结束
		最后输出换行

	while (argv[1][i] != ' ' && argv[1][i] != '\t' && argv[1][i])
		{
			write(1, &argv[1][i], 1);
			i++;
		}
	这个循环一定要加上argv[1][i]，如果已经到了字符串末尾'\0',
	那么 '\0' != ' ' || '\0' != '\t' 条件仍然成立，继续循环，会输出'\0'后面未知内容，是错的
*/

#include <unistd.h>

/*
int	main(int argc, char **argv)
{
	int	i;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (argv[1][i])
	{
		while (argv[1][i] == ' ' || argv[1][i] == '\t')
			i++;
		while (argv[1][i] != ' ' && argv[1][i] != '\t' && argv[1][i])
		{
			write(1, &argv[1][i], 1);
			i++;
		}
		while (argv[1][i] == ' ' || argv[1][i] == '\t')
			i++;
		if (argv[1][i])
			write(1, " ", 1);
	}
	write(1, "\n", 1);
	return (0);
}
*/

// 版本2 推荐
// “空格只在两个单词之间出现，不在开头/结尾出现”
int	main(int argc, char **argv)
{
	int	i;
	int	first;

	i = 0;
	first = 1; // 表示还没输出单词
	if (argc == 2)
	{
		while (argv[1][i])
		{
			// 跳过空格
			while (argv[1][i] == ' ' || argv[1][i] == '\t')
				i++;
			// 读一个单词
			if (argv[1][i] && first == 0)
				write(1, " ", 1);
			while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
			{
				write(1, &argv[1][i], 1);
				i++;
			}
			if (first == 1)
				first = 0; // 表示已经输出过单词
		}
	}
	write(1, "\n", 1);
	return (0);
}

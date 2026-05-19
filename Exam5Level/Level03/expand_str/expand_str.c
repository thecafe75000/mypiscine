/*
Assignment name  : expand_str
Expected files   : expand_str.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a program that takes a string and displays it with exactly three spaces
between each word, with no spaces or tabs either at the beginning or the end,
followed by a newline.
A word is a section of string delimited either by spaces/tabs, or by the
start/end of the string.
If the number of parameters is not 1, or if there are no words, simply display
a newline.

Examples:
$> ./expand_str "vous   voyez   c'est   facile   d'afficher   la   meme   chose" | cat -e
vous   voyez   c'est   facile   d'afficher   la   meme   chose$
$> ./expand_str " seulement          la c'est      plus dur " | cat -e
seulement   la   c'est   plus   dur$
$> ./expand_str "comme c'est cocasse" "vous avez entendu, Mathilde ?" | cat -e
$
$> ./expand_str "" | cat -e
$
$>

*/
/*
	程序接收 一个字符串参数，把里面的“单词”按原顺序输出，但要求：
		开头不能有空格或 tab
		结尾不能有空格或 tab
		单词之间必须 刚好 3 个空格，也就是每个单词之间统一为 3 个空格
		最后一定输出一个换行 \n
		只能使用函数：write
		“单词”的定义：被空格 ' '、tab '\t'、字符串开头或结尾分隔的一段字符
		如果参数数量不是 1 个，或者字符串里没有任何单词，都只输出一个换行

	核心思路：
		检查 argc 是否等于 2，因为程序名也算一个参数。
		跳过开头的空格和 tab。
		找到一个单词就输出它。
			构思：下标i指向单词开头一直输出遇到空格，tab或字符串结尾
					while (str[i] && !is_space(str[i]))
		单词之间输出三个空格，但不能在最后一个单词后面输出空格。
			构思：从第二个单词开始，每次输出单词之前，先输出三个空格，就不会在末尾多输出空格
				需要一个标记：是不是第一个单词
				if (!first)
					write(1, "   ", 3);
				first = 0;
				也就是 first == 1：当前要输出的是第一个单词
						first == 0：之前已经输出过单词了，后面的单词前面要加三个空格
				题目要求“单词之间”有三个空格，而不是“每个单词后面”有三个空格，
				用 first 可以非常自然地控制这个规则
*/
#include <unistd.h>

// 需要经常判断一个字符是不是分隔符, 因为后面会多次判断空格和 tab
int	is_space(char c)
{
	return ((c == ' ') || (c == '\t'));
}

int	main(int argc, char **argv)
{
	int	i;
	int	first;

	i = 0;
	first = 1;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			while (is_space(argv[1][i])) // 负责跳过一段空格/tab
				i++;
			if (argv[1][i])
			{
				if (!first)
					write(1, "   ", 3);
				while (argv[1][i] && !is_space(argv[1][i])) // 负责输出一个完整单词
				{
					write(1, &argv[1][i], 1);
					i++;
				}
				first = 0;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}

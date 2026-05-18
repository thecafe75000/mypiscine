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
$> ./expand_str "vous   voyez   c'est   facile   d'afficher   la   meme   chose" | cat
	-e
vous   voyez   c'est   facile   d'afficher   la   meme   chose$
$> ./expand_str " seulement          la c'est      plus dur " | cat -e
seulement   la   c'est   plus   dur$
$> ./expand_str "comme c'est cocasse" "vous avez entendu, Mathilde ?" | cat -e
$
$> ./expand_str "" | cat -e
$
$> 详细解释从0到最后完成这题的每个解题步骤, 同时解释为什么这么构思
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
		单词之间输出三个空格，但不能在最后一个单词后面输出空格。
		最后输出换行
*/
#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
	}
	write(1, "\n", 1);
	return (0);
}

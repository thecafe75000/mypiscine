/*
Assignment name  : str_capitalizer
Expected files   : str_capitalizer.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a program that takes one or several strings and, for each argument,
capitalizes the first character of each word (If it's a letter, obviously),
puts the rest in lowercase, and displays the result on the standard output,
followed by a \n.
A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string. If a word only has one letter, it must be
capitalized.
If there are no arguments, the progam must display \n.

Example:
$> ./str_capitalizer | cat -e
$
$> ./str_capitalizer "Premier PETIT TesT" | cat -e
Premier Petit Test$
$> ./str_capitalizer "DeuxiEmE tEST uN PEU moinS  facile" "   attention C'EST pas dur QUAND mEmE" "ALLer UN DeRNier 0123456789pour LA rouTE    E " | cat -e
Deuxieme Test Un Peu Moins  Facile$
   Attention C'est Pas Dur Quand Meme$
Aller Un Dernier 0123456789pour La Route    E $
$>
*/
/*
   写一个程序把输入的每句话整理成“每个单词首字母大写，其他字母小写”

   规则：
	程序从命令行参数拿字符串
	每个参数处理完输出一行
	单词只用空格和 tab 分开
	每个单词：
		第一个字母变大写
		后面的字母变小写
		数字、符号不变
	没有参数时，只输出一个空行

	每个字符只有两种位置：
		它是一个单词的第一个字符
			小写字母 -> 大写
			其他字符 -> 原样输出
		它不是单词的第一个字符
			大写字母 -> 小写
			其他字符 -> 原样输出
	怎么判断“这是单词第一个字符”：
		可以用一个变量，比如：int new_word 表示当前字符是不是单词开头
		初始时 new_word = 1 因为字符串一开始，如果第一个字符不是空格/tab，那它就是单词开头
		遍历时：
			如果遇到空格或 tab：new_word = 1 表示下一个非空格/tab 字符会是新单词开头
			如果遇到普通字符，表示已经进入一个单词内部了：
				如果 new_word == 1，按首字母规则处理
				否则按普通字母规则处理
				new_word = 0;
			即：
				new_word == 1 表示“这是单词开头位置”，如果当前字符是字母，就按首字母规则处理成大写。
				new_word == 0 表示“这是单词内部位置”，如果当前字符是字母，就按普通规则处理成小写。
				new_word 不是直接表示“这个字符要不要大写”，而是表示当前是不是新单词的开头

*/

#include <unistd.h>

int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

char	to_upper(char c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

char	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

void	str_capitalizer(char *str)
{
	int		i;
	int		new_word;
	char	c;

	i = 0;
	new_word = 1;
	while (str[i])
	{
		c = str[i];
		if (is_space(c))
			new_word = 1;
		else
		{
			if (new_word)
				c = to_upper(c);
			else
				c = to_lower(c);
			new_word = 0;
		}
		write(1, &c, 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 1)
		write(1, "\n", 1);
	while (i < argc)
	{
		str_capitalizer(argv[i]);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}

/*
Assignment name  : rstr_capitalizer
Expected files   : rstr_capitalizer.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a program that takes one or more strings and, for each argument, puts
the last character of each word (if it's a letter) in uppercase and the rest
in lowercase, then displays the result followed by a \n.
A word is a section of string delimited by spaces/tabs or the start/end of the
string. If a word has a single letter, it must be capitalized.
If there are no parameters, display \n.

Examples:
$> ./rstr_capitalizer | cat -e
$
$> ./rstr_capitalizer "Premier PETIT TesT" | cat -e
premieR petiT tesT$
$> ./rstr_capitalizer "DeuxiEmE tEST uN PEU moinS  facile" "   attention C'EST pas dur QUAND mEmE" "ALLer UN DeRNier 0123456789pour LA rouTE    E " | cat
	-e
deuxiemE tesT uN peU moinS  facilE$
   attentioN c'esT paS duR quanD memE$
alleR uN dernieR 0123456789pouR lA routE    E $
$>
*/
/*
	要求是：对每一个参数字符串，逐个字符处理并输出。
	规则：
		每个单词的最后一个字母要变成大写，单词的其余字母要变成小写
			例如：./rstr_capitalizer "Premier PETIT TesT"
			则结果应该是：premieR petiT tesT
		非字母字符不需要改大小写,也就是说，一个单词的“最后一个字符”如果是字母，就把它大写
		单词由空格 ' ' 或 tab '\t' 分隔, 也就是说，只有这两个字符能分隔单词
		每处理完一个参数，输出一个换行 \n
		如果没有参数，只输出一个换行
		如果有多个参数：
			例如：./rstr_capitalizer "abc DEF" "HELLO world"
			应该输出两行：
				abC deF
				hellO worlD

	char	c;
	c = str[i]; 这2行代码是为了拿一个临时变量处理当前字符，不改原字符串

*/

#include <unistd.h>

int	is_separator(char c)
{
	return (c == ' ' || c == '\t' || c == '\0');
}

int	is_letter(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

char	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
char	to_upper(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

void	rstr_capitalizer(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i])
	{
		c = str[i];
		if (is_letter(c))
		{
			if (is_separator(str[i + 1]))
				c = to_upper(c);
			else
				c = to_lower(c);
		}
		write(1, &c, 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		write(1, "\n", 1);
	i = 1;
	while (i < argc)
	{
		rstr_capitalizer(argv[i]);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}

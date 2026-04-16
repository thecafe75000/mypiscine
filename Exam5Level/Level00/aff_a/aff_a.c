/*
Assignment name  : aff_a
Expected files   : aff_a.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string, and displays the first 'a' character it
encounters in it, followed by a newline. If there are no 'a' characters in the
string, the program just writes a newline. If the number of parameters is not
1, the program displays 'a' followed by a newline.

Example:

$> ./aff_a "abc" | cat -e
a$
$> ./aff_a "dubO a POIL" | cat -e
a$
$> ./aff_a "zz sent le poney" | cat -e
$
$> ./aff_a | cat -e
a$
*/

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;

	// 如果参数个数不是 1 个, 就直接输出 a 和换行
	if (argc != 2)
	{
		write(1, "a\n", 2);
		return (0);
	}

	i = 0;
	// 只要当前字符不是字符串结束符 '\0', 就继续往后找
	while (argv[1][i])
	{
		// 如果当前字符是 'a', 就输出 a 和换行，然后结束程序
		if (argv[1][i] == 'a')
		{
			write(1, "a\n", 2);
			return (0);
		}
		i++;
	}
	// 如果整个字符串都没有找到 'a', 就只输出一个换行
	write(1, "\n", 1);
	return (0);
}

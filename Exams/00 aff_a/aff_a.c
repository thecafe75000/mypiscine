/*
Assignment name  : aff_a
Expected files   : aff_a.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a program that takes a string, and displays the first 'a' character it
encounters in it, followed by a newline.
If there are no 'a' characters in the string, the program just writes a newline.
If the number of parameters is not 1, the program displays 'a' followed by a newline.

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

	// 如果参数的数量不是1(即0个参数或者有2个以上的参数), 就直接输出 a 和换行
	if (argc != 2)
	{
		write(1, "a\n", 2);
		return (0); // 这个return是必须的，防止当0个参数时，后面的代码访问不存在的argv[1]崩溃
	}
	i = 0;
	// 只要当前字符不是字符串结束符 '\0', 就继续往后找
	while (argv[1][i])
	{
		if (argv[1][i] == 'a')
		{
			write(1, "a", 1);
			return (0); // 这个return必须有，防止后面还有字母a的话会继续输出打印
		}
		i++;
	}
	write(1, "\n", 1);
	return (0);
}

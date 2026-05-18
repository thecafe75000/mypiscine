/*
Assignment name  : print_hex
Expected files   : print_hex.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a program that takes a positive (or zero) number expressed in base 10,
and displays it in base 16 (lowercase letters) followed by a newline.
If the number of parameters is not 1, the program displays a newline.

Examples:
$> ./print_hex "10" | cat -e
a$
$> ./print_hex "255" | cat -e
ff$
$> ./print_hex "5156454" | cat -e
4eae66$
$> ./print_hex | cat -e
$
*/
/*
	接收一个十进制的非负整数, 即正整数和0，把它转换成十六进制小写形式输出，最后输出换行

	下面这几行代码，是把10进制数字转成16进制数字，并以倒序方式存入hex[]数组
	while (result > 0)
	{
		hex[j] = base[result % 16];
		result = result / 16;
		j++;
	}

*/
#include <unistd.h>

int	main(int argc, char **argv)
{
	int		i;
	int		result;
	char	*base;
	char	hex[16];
	int		j;

	i = 0;
	result = 0;
	base = "0123456789abcdef";
	if (argc == 2)
	{
		while (argv[1][i] >= '0' && argv[1][i] <= '9')
		{
			result = result * 10 + (argv[1][i] - '0');
			i++;
		}
		j = 0;
		if (result == 0)
			write(1, "0", 1);
		while (result > 0)
		{
			hex[j] = base[result % 16];
			result = result / 16;
			j++;
		}
		while (j > 0)
		{
			j--;
			write(1, &hex[j], 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}

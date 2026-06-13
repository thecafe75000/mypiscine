/*
Assignment name  : repeat_alpha
Expected files   : repeat_alpha.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a program called repeat_alpha that takes a string and display it
repeating each alphabetical character as many times as its alphabetical index,
followed by a newline.

'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

Case remains unchanged.

If the number of arguments is not 1, just display a newline.

Examples:
$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | cat -e
abbacccaddddabba 42!$
$>./repeat_alpha | cat -e
$
$>
$>./repeat_alpha "" | cat -e
$
$>
		c - 'A' + 1 或 c- 'a' + 1 是把字母转换成它在字母表里的序号
		利用 'a' 到 'z' 在ascii表里的数值，算出传入的字母char c 相对 'a' 的偏移量，再加 1，得到在字母表里的序号
		序号 = 当前字母 - 'a' + 1 即符合题目要求，字母序号多少，则打印输出字母的次数等于序号
*/

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	print_times;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	print_times = 0;
	while (argv[1][i])
	{
		if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
			print_times = argv[1][i] - 'a' + 1;
		else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
			print_times = argv[1][i] - 'A' + 1;
		else
			print_times = 1;
		while (print_times > 0)
		{
			write(1, &argv[1][i], 1);
			print_times--;
		}
		i++;
	}
	write(1, "\n", 1);
	return (0);
}

/*
	版本2 封装函数
		c - 'A' + 1 或 c- 'a' + 1 是把字母转换成它在字母表里的序号
		利用 'a' 到 'z' 在ascii表里的数值，算出传入的字母char c 相对 'a' 的偏移量，再加 1，得到在字母表里的序号
		序号 = 当前字母 - 'a' + 1 即符合题目要求，字母序号多少，则打印输出字母的次数等于序号

int	repeattimes(char c)
{
	int	times;

	if (c > 'A' && c <= 'Z')
		times = c - 'A' + 1;
	else if (c > 'a' && c <= 'z')
		times = c - 'a' + 1;
	else
		times = 1;
	return (times);
}

int	main(int argc, char **argv)
{
	int	times;
	int	i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			times = repeattimes(argv[1][i]);
			while (times > 0)
			{
				write(1, &argv[1][i], 1);
				times--;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
*/

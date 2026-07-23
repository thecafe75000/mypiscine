/*
Assignment name  : count_word
Expected files   : count_word.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a program that takes a string and displays its number of words followed by a newline. A word is a sequence of characters delimited by spaces or tabs,
or by the start/end of the string. If the number of arguments is not 1,
the program displays a newline.

*/
#include <unistd.h>

void	putnbr(int n)
{
	char	c;

	if (n >= 10)
		putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

int	main(int ac, char **av)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (ac != 2)
		return (write(1, "\n", 1), 0);
	while (av[1][i])
	{
		while (av[1][i] == ' ' || av[1][i] == '\t')
			i++;
		if (av[1][i] && av[1][i] != ' ' && av[1][i] != '\t')
		{
			count++;
			while (av[1][i] && av[1][i] != ' ' && av[1][i] != '\t') // 跳过整个单词
				i++;
		}
	}
	putnbr(count);
	write(1, "\n", 1);
	return (0);
}

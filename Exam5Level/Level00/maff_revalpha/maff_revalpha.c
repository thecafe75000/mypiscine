/*
Assignment name  : maff_revalpha
Expected files   : maff_revalpha.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays the alphabet in reverse, with even letters in
uppercase, and odd letters in lowercase, followed by a newline.

Example:

$> ./maff_revalpha | cat -e
zYxWvUtSrQpOnMlKjIhGfEdCbA$
*/
#include <unistd.h>

int	main()
{
	char c;
	int i;
	char temp;

	i = 0;
	c = 'z';
	while (c >= 'a')
	{
		temp = c;
		if (i % 2 != 0)
			temp -= 32;
		write(1, &temp, 1);
		i++;
		c--;
	}
	write(1, "\n", 1);
	return (0);
}

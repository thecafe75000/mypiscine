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

int main()
{
	char c;
	char upper;

	c = 'z';
	while (c >= 'a' && c <= 'z')
	{
		if ((c - 'z') % 2 == 0)
			write(1, &c, 1);
		else
		{
			upper = c - 32;
			write(1, &upper, 1);
		}
		c--;
	}
	write(1, "\n", 1);
	return (0);
}

/*
Assignment name  : maff_alpha
Expected files   : maff_alpha.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a program that displays the alphabet, with even letters in uppercase, and
odd letters in lowercase, followed by a newline.

Example:
$> ./maff_alpha | cat -e
aBcDeFgHiJkLmNoPqRsTuVwXyZ$
*/

#include <unistd.h>

int main()
{
	char c;
	int i; // i是字母表的下标，从0开始计算
	char temp;

	c = 'a';
	i = 0;
	while (c <= 'z')
	{
		temp = c;
		if (i % 2 != 0)
			temp -= 32;
		write(1, &temp, 1);
		c++;
		i++;
	}
	write(1, "\n", 1);
	return (0);
}


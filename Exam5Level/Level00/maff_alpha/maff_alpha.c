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

/*
#include <unistd.h>

int	main(void)
{
	char	c;
	int		i;

	c = 'a';
	i = 0;
	// 第一个 if：把当前小写字母临时变成大写，方便输出
	// 第二个 if：把它再变回小写 这样后面的 c++ 才能按正常字母顺序继续走 while (c <= 'z')
	while (c <= 'z')
	{
		if (i % 2 != 0)
		{
			c = c - 32;
		}
		write(1, &c, 1);
		if (i % 2 != 0)
		{
			c = c + 32;
		}
		c++;
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
*/

#include <unistd.h>

int	main(void)
{
	char	c = 'a';
	int		i = 0;
	char	temp;

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

/*
Assignment name  : fizzbuzz
Expected files   : fizzbuzz.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a program that prints the numbers from 1 to 100, each separated by a
newline.

If the number is a multiple of 3, it prints 'fizz' instead.

If the number is a multiple of 5, it prints 'buzz' instead.

If the number is both a multiple of 3 and a multiple of 5,
	it prints 'fizzbuzz' instead.

Example:
$>./fizzbuzz
1
2
fizz
4
buzz
fizz
7
8
fizz
buzz
11
fizz
13
14
fizzbuzz
[...]
97
98
fizz
buzz
$>
*/

#include <unistd.h>

int	main00(void)
{
	int		num;
	char	c;

	num = 1;
	while (num <= 100)
	{
		if (num % 3 == 0 && num % 5 == 0)
			write(1, "fizzbuzz\n", 9);
		else if (num % 3 == 0)
			write(1, "fizz\n", 5);
		else if (num % 5 == 0)
			write(1, "buzz\n", 5);
		else if (num >= 10)
		{
			c = num / 10 + '0';
			write(1, &c, 1);
			c = num % 10 + '0';
			write(1, &c, 1);
			write(1, "\n", 1);
		}
		else
		{
			c = num + '0';
			write(1, &c, 1);
			write(1, "\n", 1);
		}
		num++;
	}
	write(1, "\n", 1);
	return (0);
}

// 递归版
void	putnbr(int n)
{
	char	c;

	if (n >= 10)
		putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

int	main(void)
{
	int	num;

	num = 1;
	while (num <= 100)
	{
		if (num % 3 == 0 && num % 5 == 0)
			write(1, "fizzbuzz\n", 9);
		else if (num % 3 == 0)
			write(1, "fizz\n", 5);
		else if (num % 5 == 0)
			write(1, "buzz\n", 5);
		else
		{
			putnbr(num);
			write(1, "\n", 1);
		}
		num++;
	}
	return (0);
}

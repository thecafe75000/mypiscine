/*
Assignment name  : pgcd
Expected files   : pgcd.c
Allowed functions: printf, atoi, malloc, free
--------------------------------------------------------------------------------
Write a program that takes two strings representing two strictly positive
integers that fit in an int.
Display their highest common denominator followed by a newline (It's always a
strictly positive integer).
If the number of parameters is not 2, display a newline.

Examples:
$> ./pgcd 42 10 | cat -e
2$
$> ./pgcd 42 12 | cat -e
6$
$> ./pgcd 14 77 | cat -e
7$
$> ./pgcd 17 3 | cat -e
1$
$> ./pgcd | cat -e
$
*/
/*
	接收两个命令行参数，这两个参数是字符串形式的严格正整数，并且都能放进 int
	你要计算并输出它们的最大公约数，也就是 GCD,
	题目里写的 “highest common denominator” 实际上就是最大公约数

	要求：
		程序运行时必须传入正好 2 个参数
		如果参数数量不是 2 个，只输出一个换行
		如果参数数量是 2 个：
			用 atoi 把两个字符串转成整数
			计算它们的最大公约数
			输出结果，后面跟一个换行
		最大公约数的算法就是：
			用 x 除以 y
			记下余数
			用余数替换被除数 x 重复上诉过程
			直到余数为0，最后那个数就是最大公约数
		gcd(x, y) = gcd(y, x%y)
		每次用y替换x, x%y替换y 直到出现x%
		例如：gcd(42, 12) 变成 gcd(12, 42 % 12), 也就是变成 gcd(12, 6)
		也就是这3行代码：
			temp = y;
			y = x % y;
			x = temp;
		核心规律：
			gcd(a, b) == gcd(b, a % b)
			直到 b == 0，这时 a 就是最大公约数
*/
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	x;
	int	y;
	int	temp;

	if (argc == 3)
	{
		x = atoi(argv[1]);
		y = atoi(argv[2]);
		while (y != 0)
		{
			temp = y;
			y = x % y;
			x = temp;
		}
		printf("%d", x);
	}
	printf("\n");
	return (0);
}

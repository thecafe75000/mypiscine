/*
Assignment name  : lcm
Expected files   : lcm.c
Allowed functions:
--------------------------------------------------------------------------------
Write a function who takes two unsigned int as parameters and returns the
computed LCM of those parameters.
LCM (Lowest Common Multiple) of two non-zero integers is the smallest postive
integer divisible by the both integers.
A LCM can be calculated in two ways:
- You can calculate every multiples of each integers until you have a common
multiple other than 0
- You can use the HCF (Highest Common Factor) of these two integers and
calculate as follows:
		LCM(x, y) = | x * y | / HCF(x, y)
  | x * y | means "Absolute value of the product of x by y"
If at least one integer is null, LCM is equal to 0.

Your function must be prototyped as follows:
  unsigned int    lcm(unsigned int a, unsigned int b);
*/
/*
	函数接收两个 unsigned int 类型的整数 a 和 b，返回它们的最小公倍数 LCM。

	要求：
		如果 a 或 b 其中一个是 0，返回 0。
		如果两个数都不是 0，返回它们的最小公倍数。
		只能提交 lcm.c 这个文件。
		不需要写 main，只写函数本身即可。
		LCM 的意思是 “最小公倍数”：
			LCM 是一个最小的正整数 n，它同时满足 n % a == 0 和 n % b == 0
			也就是：LCM既是a的倍数，又是b的倍数，但是它们共同的最小倍数
			比如: 4 和 6 的共同倍数有12，24...，最小的共同倍数是12

	如何获取2个整数的最小公倍数？
		公式：最小公倍数 = 两个整数相乘 / 这2个整数的最大公约数
				LCM(a, b) = a * b / gcd(a, b)
		比如获取 4 和 6 的最小公倍数 n：
			n = 4 * 6 / 2 = 12
			2 是 4 和 6 的最大公约数

	按“从 0 开始写出完整程序”的方式解释这题怎么想、怎么拆、为什么这样构思
*/

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned	x;
	unsigned	y;
	unsigned	temp;
	unsigned	gcd;

	if (a == 0 || b == 0)
		return (0);
	x = a;
	y = b;
	while (y != 0)
	{
		temp = y;
		y = x % y;
		x = temp;
	}
	gcd = x;
	return ((a / gcd) * b);
}

#include <stdio.h>

int	main(void)
{
	printf("result = %u\n", lcm(0, 8));
	printf("result = %u\n", lcm(12, 0));
	printf("result = %u\n", lcm(4, 6));
	printf("result = %u\n", lcm(3, 5));
	return (0);
}

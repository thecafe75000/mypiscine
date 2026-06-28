/*
Assignment name  : fprime
Expected files   : fprime.c
Allowed functions: printf, atoi
--------------------------------------------------------------------------------
Write a program that takes a positive int and displays its prime factors on the
standard output, followed by a newline.
Factors must be displayed in ascending order and separated by '*', so that
the expression in the output gives the right result.
If the number of parameters is not 1, simply display a newline.
The input, when there's one, will be valid.

Examples:
$> ./fprime 225225 | cat -e
3*3*5*5*7*11*13$
$> ./fprime 8333325 | cat -e
3*3*5*5*7*11*13*37$
$> ./fprime 9539 | cat -e
9539$
$> ./fprime 804577 | cat -e
804577$
$> ./fprime 42 | cat -e
2*3*7$
$> ./fprime 1 | cat -e
1$
$> ./fprime | cat -e
$
$> ./fprime 42 21 | cat -e
$
*/
/*
	写一个程序：
		接收一个正整数，把它分解成质因数，并按从小到大的顺序输出
		每个因数之间用 * 连接，最后输出换行
	要求总结：
		程序参数必须刚好是 1 个数字：
			如果参数数量不是 1 个，只输出一个换行
		输入保证合法：
			如果有一个参数，它一定是有效的正整数
			不需要处理非法字符串、负数、小数等情况
		输出质因数：
			从小到大
			用 * 分隔
			最后必须有 \n
		如果输入本身就是质数，直接输出它自己
			9539 输出 9539
		如果输入是 1，输出 1
	这题重点不是判断一个数是不是质数，而是不断用最小可能因子去除它，这样天然会得到升序的质因数
	核心思路：
		从最小的质因数 2 开始试除，比如：
			n = 42
			42 能被 2 整除 -> 输出 2，n 变成 21
			21 不能被 2 整除 -> 试 3
			21 能被 3 整除 -> 输出 3，n 变成 7
			7 不能被 3 整除 -> 继续试
			最后剩下 7 -> 输出 7
			最终得到：2 * 3 * 7

	质因数 = 能把这个数整除，并且自己是质数的数，
	比如能整除数字12的数有：1, 2, 3, 4, 6, 12, 其中质数有 2, 3
	那么 2 和 3是 12 的质因数

	但这道题要注意一点：它不是只输出“不重复的质因数”，而是要输出把这个数完整拆开后需要的所有质数因子。
	比如：12 = 2 * 2 * 3
	所以程序要输出 2 * 2 * 3
	可以这么理解：
		能整除某个数字的数叫因数；能整除它并且自己是质数的数，才叫质因数
	所有大于 1 的正整数都可以分解成质因数，因此所有大于 1 的正整数都可以被拆成一串质数相乘
	比较特殊的是数字1, 1 不是质数，也没有质因数

	核心记法：
		能除就输出并缩小 num；
		不能除就换下一个 factor；
		从 2 开始，所以输出天然从小到大
*/

#include <stdio.h>
#include <stdlib.h>

// factor指的是当前正在尝试的”候选因数“
// first 的作用是：控制什么时候打印 *
int	main(int argc, char **argv)
{
	int	num;
	int	factor;
	int	first;

	if (argc != 2)
	{
		printf("\n");
		return (0);
	}
	num = atoi(argv[1]);
	factor = 2;
	first = 1;
	if (num <= 1)
	{
		printf("1\n");
		return (0);
	}
	while (num > 1)
	{
		if (num % factor == 0)
		{
			if (first == 0)
				printf("*");
			printf("%d", factor);
			first = 0;
			num = num / factor;
		}
		else
			factor++; // 如果 num 不能被当前的 factor 整除，就换下一个候选因数factor
	}
	printf("\n");
	return (0);
}

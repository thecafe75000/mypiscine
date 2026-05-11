/*
Assignment name  : swap_bits
Expected files   : swap_bits.c
Allowed functions:
--------------------------------------------------------------------------------
Write a function that takes a byte, swaps its halves (like the example) and
returns the result.
Your function must be declared as follows:
unsigned char	swap_bits(unsigned char octet);
Example:
  1 byte
_____________
 0100 | 0001
	\ /
	/ \
 0001 | 0100

*/
/*
	接收一个字节 octet, 也就是参数octet的取值范围是0 ~ 255，
	把它的 高 4 位 和 低 4 位 交换 (即其二进制的左边4位和右边4位交换)，
	然后返回交换后的结果
*/
/*
	| 的作用就是“把有 1 的地方保留下来”
	先左移位再右移位，先右移位再左移位都可以
	因为两边都是用原始的 octet 计算临时结果，然后再合并
	但不可以把它理解成：
	octet = octet << 4;
	octet = octet >> 4;
	return (octet);
	octet没有被改变
*/
unsigned char	swap_bits(unsigned char octet)
{
	return ((octet << 4) | (octet >> 4));
}

#include <stdio.h>

// 打印出二进制结果
void	print_bits(unsigned char octet)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		printf("%d", (octet >> i) & 1);
		i--;
	}
}

int	main(void)
{
	unsigned char	x;

	x = 21;
	printf("before swap x = %d \n", x);
	printf("after swap x = %d \n", swap_bits(x));
	printf("x original binary : ");
	print_bits(x);
	printf("\n");
	printf("x reversed binary : ");
	print_bits(swap_bits(x));
	printf("\n\n");
	return (0);
}

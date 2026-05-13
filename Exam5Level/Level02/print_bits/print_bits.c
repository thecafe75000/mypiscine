/*
Assignment name  : print_bits
Expected files   : print_bits.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a function that takes a byte, and prints it in binary WITHOUT A NEWLINE
AT THE END.
Your function must be declared as follows:
void	print_bits(unsigned char octet);
Example, if you pass 2 to print_bits, it will print "00000010"
*/
/*
	接收一个 unsigned char 类型的字节，把它的二进制形式打印出来，固定打印 8 位，并且结尾不要换行
	因为一个byte是8位，核心思路是从最高位到最低位检查每一位
	一个字节有 8 个 bit，每个 bit 只能是 0 或 1
	unsigned char 通常占 1 个字节，也就是 8 位，它能表示的范围是 0~255

	& 1 的作用是只保留最后一位，例如：
		00000001 & 00000001 = 1
		00000000 & 00000001 = 0
		00000101 & 00000001 = 1
	所以 (octet >> i) & 1 结果只会是 0 或 1

	bit 位的下标通常也是从 0 开始排的, 对一个 8 位 byte 来说，下标是：
	bit 7  bit 6  bit 5  bit 4  bit 3  bit 2  bit 1  bit 0
	128    64     32     16      8      4      2      1
	也就是说最右边是 bit 0, 最左边是 bit 7
	每一位都有自己的数值，就是 2 的幂：
		bit 0 = 2^0 = 1
		bit 1 = 2^1 = 2
		bit 2 = 2^2 = 4
		bit 3 = 2^3 = 8
		bit 4 = 2^4 = 16
		bit 5 = 2^5 = 32
		bit 6 = 2^6 = 64
		bit 7 = 2^7 = 128

	bit 下标从右往左数，从 0 开始, 但打印时从左往右打，所以循环从 7 到 0
*/

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int		i;
	char	bit;

	i = 7;
	while (i >= 0)
	{
		bit = ((octet >> i) & 1) + '0';
		write(1, &bit, 1);
		i--;
	}
}

#include <stdio.h>

int	main(void)
{
	print_bits(1);
	printf("\n");
	print_bits(255);
	printf("\n");
	print_bits(10);
	printf("\n");
	return (0);
}

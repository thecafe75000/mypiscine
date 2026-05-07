/*
Assignment name  : reverse_bits
Expected files   : reverse_bits.c
Allowed functions:
--------------------------------------------------------------------------------
Write a function that takes a byte, reverses it, bit by bit (like the
example) and returns the result.
Your function must be declared as follows:
unsigned char	reverse_bits(unsigned char octet);
Example:

  1 byte
_____________
 0010  0110
		||
		\/
 0110  0100
*/
/*
	把一个 unsigned char（1 个字节byte，8 个位 bit）从左到右完全反过来
	在绝大多数现代系统中：unsigned char 占 1 byte, 也就是 8 bits
	因此这题默认unsigned char == 1 byte == 8 bits
	也就是unsigned char 通常是 8 bit，对应的十进制取值范围是：0 ~ 255
	例如：
	bit 7 bit 6 bit 5 bit 4 bit 3 bit 2 bit 1 bit 0
		0     0     1     0     0     1     1     0
	反转后：
	bit 7 bit 6 bit 5 bit 4 bit 3 bit 2 bit 1 bit 0
		0     1     1     0     0     1     0     0
	也就是：
	原始字节：0010 0110
	反转之后：0110 0100

	1 byte 等于 8 bit(bit 就是二进制位，只能存0或1)
	一个 byte 的 8 个 bit 对应的数值从右往左看是：
	第 0 位：1
	第 1 位：2
	第 2 位：4
	第 3 位：8
	第 4 位：16
	第 5 位：32
	第 6 位：64
	第 7 位：128
	也就是：因为二进制是 逢 2 进 1，因此二进制每往左一位，权重乘以 2
	2^0 = 1
	2^1 = 2
	2^2 = 4
	2^3 = 8
	2^4 = 16
	2^5 = 32
	2^6 = 64
	2^7 = 128
*/
/*
unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	result;
	unsigned char	read_bit;
	unsigned char	write_bit;
	int				i;

	result = 0;
	read_bit = 1;
	write_bit = 128;
	i = 0;
	while (i < 8)
	{
		if (octet & read_bit)
			result = result + write_bit;
		read_bit = read_bit * 2;
		write_bit = write_bit / 2;
		i++;
	}
	return (result);
}
*/

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	result;

	result = 0;
	if (octet & 1)
		result = result + 128;
	if (octet & 2)
		result = result + 64;
	if (octet & 4)
		result = result + 32;
	if (octet & 8)
		result = result + 16;
	if (octet & 16)
		result = result + 8;
	if (octet & 32)
		result = result + 4;
	if (octet & 64)
		result = result + 2;
	if (octet & 128)
		result = result + 1;
	return (result);
}

/*
unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	result;
	int				i;

	result = 0;
	i = 8;
	while (i > 0)
	{
		result = result << 1;
		result = result | (octet & 1);
		octet = octet >> 1;
		i--;
	}
	return (result);
}
*/

#include <stdio.h>

// 打印出二进制结果
void	print_bits(unsigned char octet)
{
	unsigned char	bit;
	int				i;

	bit = 128;
	i = 0;
	while (i < 8)
	{
		if (octet & bit)
			printf("1");
		else
			printf("0");
		bit = bit / 2;
		i++;
		if (i == 4)
			printf(" ");
	}
}
int	main(void)
{
	unsigned char	x;
	unsigned char	y;

	x = 1;
	y = reverse_bits(x);
	printf("x = %u\n", x);
	printf("y = %u\n", y);
	printf("x original binary : ");
	print_bits(x);
	printf("\n");
	printf("x reversed binary : ");
	print_bits(y);
	printf("\n");
	return (0);
}

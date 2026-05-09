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
	一个 byte 的 8 个 bit，每个二进制的位对应的十进制数值以及反转后的值如下：
	第 0 位：1 -> result 的第 7 位，也就是 128
	第 1 位：2 -> result 的第 6 位，也就是 64
	第 2 位：4 -> result 的第 5 位，也就是 32
	第 3 位：8 -> result 的第 4 位，也就是 16
	第 4 位：16 -> result 的第 3 位，也就是 8
	第 5 位：32 -> result 的第 2 位，也就是 4
	第 6 位：64 -> result 的第 1 位，也就是 2
	第 7 位：128 -> result 的第 0 位，也就是 1
	也就是：因为二进制是 逢 2 进 1，因此二进制每往左一位，权重乘以 2
	2^0 = 1 意味着 octet 第 0 位是 1 -> result 第 7 位设为 1
	2^1 = 2 意味着 octet 第 1 位是 1 -> result 第 6 位设为 1
	2^2 = 4 意味着 octet 第 2 位是 1 -> result 第 5 位设为 1
	2^3 = 8 意味着 octet 第 3 位是 1 -> result 第 4 位设为 1
	2^4 = 16 意味着 octet 第 4 位是 1 -> result 第 3 位设为 1
	2^5 = 32 意味着 octet 第 5 位是 1 -> result 第 2 位设为 1
	2^6 = 64 意味着 octet 第 6 位是 1 -> result 第 1 位设为 1
	2^7 = 128 意味着 octet 第 7 位是 1 -> result 第 0 位设为 1

	所有 8 位反转后仍等于自己的数, 在 unsigned char 的 8 位范围 0 ~ 255 里，
	一共有 16 个 数满足, 因为它们都有一个共同特点，即二进制左右对称，这16个数是：
	0 24 36 60 66 90 102 126 129 153 165 189 195 219 231 255

	octet & 1    // 0000 0001，检查第 0 位
	octet & 2    // 0000 0010，检查第 1 位
	octet & 4    // 0000 0100，检查第 2 位
	octet & 8    // 0000 1000，检查第 3 位
	octet & 16   // 0001 0000，检查第 4 位
	octet & 32   // 0010 0000，检查第 5 位
	octet & 64   // 0100 0000，检查第 6 位
	octet & 128  // 1000 0000，检查第 7 位
*/
/*代码做了2件事情：
		1. 用 octet & 某个数，检查 octet 的某一位是不是 1
		2. 如果那一位是 1，就把 result 中“反方向对应的位置”设置成 1
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
*/

/*
	bit 反转的核心：
		octet & 某个值：检查 octet 的某一位是不是 1
		result | 某个值：把 result 的某一位设置成 1
	也就是：
	& 用来“检查 octet 的某一位是不是 1”
	| 不会破坏原来已经是 1 的位，它只会把新的目标位也设置成 1
	只要检查到某一位是 1，就把 result 中反方向对应的位置设置成 1
	如果原本某一位是 0，对应的 if 不成立，result 的那个反向位置就保持默认的 0
	这就是bit反转需要做的事情

	在 0~255 的 8 位范围内，代码逐位检查 octet；
	如果某位是 1，就把 result 中镜像位置设为 1；
	如果某位是 0，就什么也不做，result 的镜像位置保持 0；
	因此最终得到 bit 反转结果

	& 是 按位与，规则是：两个都是 1，结果才是 1；只要有一个是 0，结果就是 0
	0 & 0 = 0
	0 & 1 = 0
	1 & 0 = 0
	1 & 1 = 1

	| 是 按位或，规则是：只要有一个是 1，结果就是 1， 两个都是 0，结果才是 0
		0 | 0 = 0
		0 | 1 = 1
		1 | 0 = 1
		1 | 1 = 1
*/
unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	result;

	result = 0;
	// 如果 octet 的第 0 位是 1，就把 result 的第 7 位设置成 1
	// 2^0 = 1
	if (octet & 1)
		result = result | 128;
	// 如果 octet 的第 1 位是 1，就把 result 的第 6 位设置成 1，后面的if以此类推
	// 2^1 = 2
	if (octet & 2)
		result = result | 64;
	// 2^2 = 4, 后面的if里的8 16... 2^7 = 128 以此类推
	if (octet & 4)
		result = result | 32;
	if (octet & 8)
		result = result | 16;
	if (octet & 16)
		result = result | 8;
	if (octet & 32)
		result = result | 4;
	if (octet & 64)
		result = result | 2;
	if (octet & 128)
		result = result | 1;
	return (result);
}

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
	unsigned char	a;
	unsigned char	b;

	x = 38;
	y = reverse_bits(x);
	printf("x = %u\n", x);
	printf("y = %u\n", y);
	printf("x original binary : ");
	print_bits(x);
	printf("\n");
	printf("x reversed binary : ");
	print_bits(y);
	printf("\n\n");
	a = 'a';
	b = reverse_bits(a);
	printf("a = %u\n", a);
	printf("b = %u\n", b);
	printf("a original binary : ");
	print_bits(a);
	printf("\n");
	printf("a reversed binary : ");
	print_bits(b);
	printf("\n");
	return (0);
}

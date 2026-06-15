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

	题目要求：
	接收一个 unsigned char 类型的字节，把它的二进制形式打印出来，固定打印 8 位，并且结尾不要换行

	因为一个byte是8位，核心思路是从最高位到最低位检查每一位
	一个字节有 8 个 bit，每个 bit 只能是 0 或 1
	unsigned char 通常占 1 个字节，也就是 8 位，
	unsigned char 的取值范围是 0~255

	& 1 的作用是只保留最后一位，例如：
		00000001 & 00000001 = 1
		00000000 & 00000001 = 0
		00000101 & 00000001 = 1
	所以 (octet >> i) & 1 结果只会是 0 或 1

	bit 位的下标通常也是从 0 开始排的, 对一个 8 位 byte 来说，下标是：
	bit 7  bit 6  bit 5  bit 4  bit 3  bit 2  bit 1  bit 0
	128    64     32     16      8      4      2      1
	也就是说最右边是 bit 0, 最左边是 bit 7
	每一位都有自己的位置权值，就是 2 的幂：
		bit 0 = 2^0 = 1
		bit 1 = 2^1 = 2
		bit 2 = 2^2 = 4
		bit 3 = 2^3 = 8
		bit 4 = 2^4 = 16
		bit 5 = 2^5 = 32
		bit 6 = 2^6 = 64
		bit 7 = 2^7 = 128

	bit 下标从右往左数，从 0 开始, 但打印时从左往右打，所以循环从 7 到 0
	1个byte的值是所有bit权值的“组合和”，例如：
	255 = 128+64+32+16+8+4+2+1

	核心代码：
	bit = ((octet >> i) & 1) + '0';
		octet 是一个 unsigned char，通常是 8 位，比如 5 的二进制是 00000101
		octet 本质是：8 个 bit 的组合, 是1byte数值，取值范围0~255
		i = 7 从最高位开始，依次到 0，即从左到右，先打印最高位，再打印最低位
		octet >> i 把第 i 位移动到最右边
		& 1 只保留最右边这一位，结果要么是 0，要么是 1
		+ '0' 把数字 0/1 转成字符 '0'/'1'
*/

#include <unistd.h>

// 版本1：通过“位下标”访问 bit
void	print_bits00(unsigned char octet)
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
	write(1, "\n", 1);
}

/*
	版本2：通过“掩码 mask”检测 bit，用 mask 去检查某一位是否为1
	从高位到低位，逐位检查 octet 的每个 bit 是否为 1

	按位与规则：
	1 & 1 = 1
	1 & 0 = 0
	0 & 1 = 0
	0 & 0 = 0

	mask / 2 = 所有位权整体减 1 次幂（2^n → 2^(n-1)）
	二进制的位权是 2^n，除以 2 等价于让唯一的 1 在位权系统中下降一层，从而实现逐位扫描

	参数octet 本质是：8 个 bit 的组合, 是1byte数值，取值范围0~255

	if (octet & mask) 判断 octet 在 mask 对应的那一位是不是 1
*/
void	print_bits(unsigned char octet)
{
	unsigned char	mask;
	char			bit;

	mask = 128;
	while (mask > 0)
	{
		if (octet & mask) // 根据按位与规则，只有两个位置都为1时结果才是1，等于在检测当前这一位是不是 1
			bit = '1';
		else
			bit = '0';
		write(1, &bit, 1);
		mask = mask / 2; // mask 的 1 不断右移, 依次检查下一位, 除以2则所有 bit 整体右移一位
	}
	write(1, "\n", 1);
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

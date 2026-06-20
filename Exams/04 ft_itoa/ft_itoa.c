/*
Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------
Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:
char	*ft_itoa(int nbr);

	把一个 int 整数转换成一个 C 字符串
	考你能不能自己把整数拆成每一位字符，并且正确申请内存保存最终字符串
	具体要求：
		参数 nbr 是一个整数，比如 123、-42、0。
		函数要返回一个 char *，也就是字符串地址。
		返回的字符串必须是你在函数里用 malloc 分配出来的字符数组。
		字符串必须以空字符 '\0' 结尾
		如果是负数，字符串里要包含负号 '-'。
		要正确处理特殊值，比如：
			0 应返回 "0"
			42 应返回 "42"
			-42 应返回 "-42"
			-2147483648 也要能正确转换

	核心构思：
		先算这个整数变成字符串需要几个字符, 即字符串长度
		用 malloc 申请 长度 + 1 的空间。
		最后一位放 '\0'，str[len] = '\0'
		当输入的参数只有0时，要专门处理这个0，str[0] = '0'
		如果是负数，先放 '-'，再把数字转成正数
		用 % 10 取最后一位，用 / 10 去掉最后一位
		因为取出来是反的，所以从字符串末尾往前填, 即从后往前填数字
*/

#include <stdlib.h>

// 计算整数 nbr 转成字符串以后，需要多少个可见字符
// 也就是字符串的长度，注意不包括最后的'\0'
int	get_length(int nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0) // 先把负号位算进去，如果是0，数字0本身也要占用一个字符空间，同样要长度
		len++;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	int		len;
	char	*str;
	long	num;

	len = get_length(nbr);
	num = nbr;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0'; // 先放字符串结束符
	if (num == 0)
		str[0] = '0';
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		str[len - 1] = (num % 10) + '0'; // 从字符串末尾往前填, 获取最后一位数字
		num = num / 10;                  // 去掉最后一位数字
		len--;
	}
	return (str);
}

#include <stdio.h>

int	main(void)
{
	char	*str;

	str = ft_itoa(-2147483648);
	printf("%s\n", str);
	free(str);
	return (0);
}

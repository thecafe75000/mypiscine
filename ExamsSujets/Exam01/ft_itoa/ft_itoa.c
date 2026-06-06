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
		先算这个整数nbr变成字符串需要几个字符。
		用 malloc 申请 长度 + 1 的空间，即 malloc(len + 1)，多出来的 1 个位置放 '\0'
		先放 '\0'
		如果是 0，直接写 '0'
		如果是负数，先放 '-'，再把数字转成正数。
		用 % 10 获取最后一位数字，用 / 10 去掉最后一位数字
		因为取出来是反的，所以从字符串末尾往前填
		返回字符串
*/

#include <stdlib.h>

// 计算nbr转成字符串后的字符串长度，不包括后面的'\0'
int	get_length(int nbr)
{
	int	i;

	i = 0;
	// 对 int类型的数字来说，负数最多只需要一个负号
	if (nbr < 0)
		i++;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}
char	*ft_itoa(int nbr)
{
	int		len;
	char	*itoa;
	long	num;

	len = get_length(nbr);
	itoa = malloc(sizeof(char) * (len + 1));
	if (!itoa)
		return (NULL);
	itoa[len] = '\0'; // 先放字符串结束符
	num = nbr;
	if (num == 0)
		itoa[0] = '0';
	if (num < 0)
	{
		itoa[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		itoa[len - 1] = (num % 10) + '0'; // 从字符串末尾往前填, 获取最后一位数字
		num = num / 10;                   // 去掉最后一位数字
		len--;
	}
	return (itoa);
}

#include <stdio.h>

int	main(void)
{
	char	*str1;
	char	*str2;
	char	*str3;

	str1 = ft_itoa(-2147483648);
	printf("%s\n", str1);
	str2 = ft_itoa(2147483647);
	printf("%s\n", str2);
	str3 = ft_itoa(0);
	printf("%s\n", str3);
	free(str1);
	free(str2);
	free(str3);
	return (0);
}

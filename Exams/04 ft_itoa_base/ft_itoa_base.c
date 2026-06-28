/*
Assignment name  : ft_itoa_base
Expected files   : ft_itoa_base.c
Allowed functions: malloc
--------------------------------------------------------------------------------
Write a function that converts an integer value to a null-terminated string
using the specified base and stores the result in a char array that you must
allocate.
The base is expressed as an integer, from 2 to 16.
The characters comprising the base are the digits from 0 to 9,followed by uppercase letter from A to F.
组成该进制的字符包括数字 0 到 9，以及后面的从 A 到 F 的大写字母, 即16进制的字符集合

For example, base 4 would be "0123" and base 16 "0123456789ABCDEF".

If base is 10 and value is negative, the resulting string is preceded with a
minus sign (-). With any other base, value is always considered unsigned.

Your function must be declared as follows:
char				*ft_itoa_base(int value, int base);

	把一个 int 整数 value 转成指定进制 base 的字符串，并返回这个字符串
	参数：
		value 表示要转换的整数
		base 表示：你想把这个整数转换成几进制
		例如：ft_itoa_base(42, 2) 意思是把 42 转成二进制字符串
		注意：只有 base == 10 且 value 是负数时，才显示负号，例如：
			ft_itoa_base(-42, 10) -> "-42"
		如果 base 不是 10，负数会被当成无符号数处理
	要求：
		只能使用 malloc
		base 的范围是 2 到 16之间的任意进制，进制字符固定为：0123456789ABCDEF，例如：
			base = 2：二进制
			base = 8：八进制
			base = 10：十进制
			base = 16：十六进制
		负数处理规则：只有当base == 10 && value < 0时，结果前面才加 -，例如：
			ft_itoa_base(-42, 10) 返回 “-42”，
		但如果不是10进制，负数要当做unsigned来处理，例如 -1：
			ft_itoa_base(-1, 16)， -1应该按无符号数 4294967295 处理，结果是："FFFFFFFF"
			也就是 把 -1 当成 2^32 - 1，然后正常转 16 进制
		函数需要自己计算字符串长度并分配内存，例如：
			ft_itoa_base(255, 16) 返回 “FF”，需要分配3个字符空间'F' 'F' '\0'

	进制转换的本质就是：
		digit = number % base; (是在拿“当前这一轮的最后一位”)
		number = number / base;(是在把这个最后一位去掉，继续处理剩下的部分)
		number 表示：当前还没有转换完的那个数
		digit 表示：当前算出来的最低一位数字
		例如：
			digit = 1234 % 10; // 4
			number = 1234 / 10; // 123

	核心逻辑就是：
		判断是否需要负号。
		把 value 转成一个无符号数来处理。
		计算转换后需要多少位。
		malloc 分配空间。
		从后往前填入对应进制字符。
		最后返回字符串。

*/

#include <stdlib.h>

// 计算转换后需要多少个字符，即字符串的长度
// 长度和 base 有关, 不同的base，转成字符串时的长度不同
int	get_length(unsigned int nbr, int base, int sign)
{
	int	len;

	// 因为即使是 0，长度也要有一位
	len = 1;
	// 只要这个数还没有缩小到“一位数范围内”，就继续除
	while (nbr >= (unsigned int)base)
	{
		nbr = nbr / base;
		len++;
	}
	//  最终字符串长度 = 数字位数 + 负号长度
	return (len + sign);
}

/*
 该函数用于将 int 转换为 unsigned int 以便进行进制输出，并且仅在十进制且值为负时，
 通过 sign 标记符号，同时返回其绝对值
 即把 value 转成真正要处理的 unsigned int 数字，同时告诉外面需不需要负号
 */
static unsigned int	get_nbr(int value, int base, int *sign)
{
	*sign = 0;
	if (base == 10 && value < 0)
	{
		*sign = 1;
		return (-(unsigned int)value);
	}
	return ((unsigned int)value);
}
/*
	ft_itoa_base 应该按这个顺序写：
		1. 得到真正要转换的数字 nbr
		2. 得到是否有负号 has_minus
		3. 计算字符串长度 len
		4. malloc len + 1 个字符
		5. 最后一位放 '\0'
		6. 从后往前填数字字符
		7. 如果有负号，str[0] = '-'
		8. 返回 str
*/
char	*ft_itoa_base(int value, int base)
{
	char			*str;
	unsigned int	nbr;
	int				sign;
	int				len;

	nbr = get_nbr(value, base, &sign);
	len = get_length(nbr, base, sign);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len > sign)
	{
		str[len - 1] = "0123456789ABCDEF"[nbr % base];
		nbr = nbr / base;
		len--;
	}
	if (sign == 1)
		str[0] = '-';
	return (str);
}

#include <stdio.h>

void	test(int value, int base)
{
	char	*result;

	result = ft_itoa_base(value, base);
	printf("ft_itoa_base(%d, %d) = %s\n", value, base, result);
}
int	main(void)
{
	test(0, 10);
	test(42, 10);
	test(-42, 10);
	test(42, 2);
	test(42, 16);
	test(255, 16);
	test(15, 16);
	test(16, 16);
	test(-1, 16);
	test(-42, 16);
	test(-42, 2);
	test(-2147483648, 10);
	return (0);
}

/*
Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------
Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.
The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".
Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".
Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:
int	ft_atoi_base(const char *str, int str_base);

	题目要求：
	把一个字符串形式的数字（任意进制 ≤ 16）转换成 十进制 int 返回，str_base 的范围：2 ≤ base ≤ 16
	即接收一个字符串 str，并且把这个字符串当作 str_base 进制写出来的数字，然后计算出它对应的十进制整数值并返回
	也就是：
		str       是“某个进制写出来的数字字符串”
		str_base  告诉函数：str 当前是什么进制，不是要把 str 转换成什么进制
		str_base 的作用不是“目标进制”，而是“读取 str 时使用的是哪种进制
		返回值     把str算成十进制 int
	str_base 表示输入字符串使用的进制，最大是 16进制，
	而且16进制大小写字母都支持，也就是说 ft_atoi_base("ff", 16) == ft_atoi_base("FF", 16)
	比如：
		ft_atoi_base("1010", 2) -> "1010" 是二进制, 把它转成十进制整数
	核心意思是把 str 当作 str_base 进制的数字字符串，把str转换成十进制 int 返回。

	不同进制只能使用对应范围内的字符：
		base 2  只认 0 1
		base 4  只认 0 1 2 3
		base 10 只认 0-9
		base 16 只认 0-9 a-f A-F
	遇到不属于当前进制的字符，就停止转换, 能读多少合法数字，就转换多少；即遇到当前进制不认识的字符，就停
	比如：ft_atoi_base("124", 4)的参数的意思是把字符串"124"当作4进制来读，然后转成十进制
			4进制即base 4 允许 0 1 2 3，
			4 在 base 4 里非法，所以只转换前面的 "12"
	只有当 - 是字符串第一个字符时，才表示负数

	普通十进制转换公式是：
		result = result * 10 + 当前数字;
	如果是其他进制，只要把 10 换成对应进制：
		result = result * str_base + 当前数字;
	另外：
		数字转字符：+ '0'
		字符转数字：- '0'

	思路：
		1. result = 0
		2. sign = 1
		3. 如果第一个字符是 '-'，sign = -1，并跳过它
		4. 从左到右遍历字符
		5. 把字符转成数字 num
		6. 如果 num < 0 或 num >= str_base 就停止
		7. result = result * str_base + num
		8. 最后返回 result * sign
*/

int	is_space(char c)
{
	if ((c >= '9' && c <= 13) || c == ' ')
		return (1);
	return (0);
}
int	get_num(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10); // 0–9 已经被数字字符占用了，a–f 必须从 10 开始接着往后排
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (-1);
}
int	ft_atoi_base(const char *str, int str_base)
{
	int	i;
	int	sign;
	int	result;
	int	num;

	i = 0;
	sign = 1;
	result = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		num = get_num(str[i]);
		if (num < 0 || num >= str_base)
			break ;
		result = result * str_base + num;
		i++;
	}
	return (result * sign);
}

#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_atoi_base("011", 2));
	printf("%d\n", ft_atoi_base("16", 8));
	printf("%d\n", ft_atoi_base("123", 10));
	printf("%d\n", ft_atoi_base("FF", 16));
	return (0);
}

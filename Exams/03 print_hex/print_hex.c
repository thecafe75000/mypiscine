/*
Assignment name  : print_hex
Expected files   : print_hex.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a program that takes a positive (or zero) number expressed in base 10,
and displays it in base 16 (lowercase letters) followed by a newline.
If the number of parameters is not 1, the program displays a newline.

Examples:
$> ./print_hex "10" | cat -e
a$
$> ./print_hex "255" | cat -e
ff$
$> ./print_hex "5156454" | cat -e
4eae66$
$> ./print_hex | cat -e
$

	题目要求：
	把命令行输入的十进制数字字符串，转换成十六进制并输出（小写），最后输出换行

	下面这几行代码，是把10进制数字转成16进制数字，并以倒序方式存入hex[]数组
	while (result > 0)
	{
		hex[j] = base[result % 16]; // 余数法天然生成“逆序数字”
		result = result / 16;  // 去掉当前最低位
		j++;
	}
	while (j > 0) // 上面用倒序的方式把数字存入数组，因此输出就要反向输出才能输出正确数字
	{
		j--;
		write(1, &hex[j], 1);
	}

	为什么不先把高位存入数组，然后正常顺序输出呢？
	不是不能做，而是“整数除法的天然行为”决定了你很难直接得到高位，只能先得到低位
	但在纯整数运算里，你只有：
		% 10（或 % 16） 拿最低位
		/ 10（或 / 16） 去掉最低位，拿到高位的数字
	你没有任何操作可以直接拿“最高位”
*/

#include <unistd.h>

int	main(int argc, char **argv)
{
	int		i;
	int		result;
	char	*base;
	char	hex[16];
	int		j;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	result = 0;
	base = "0123456789abcdef";
	// 把数字字符串转换为int整数
	while (argv[1][i] >= '0' && argv[1][i] <= '9')
	{
		result = result * 10 + (argv[1][i] - '0');
		i++;
	}
	if (result == 0) // 0 是进制转换算法中的特殊值，通常需要单独处理
		write(1, "0", 1);
	j = 0;
	// 获取的结果里数字的顺序是反的，因此要正确输出结果，也必须每个字符倒着输出
	while (result > 0)
	{
		hex[j] = base[result % 16];
		result = result / 16;
		j++;
	}
	// 倒着输出hex[j]才会正确展示结果
	while (j > 0)
	{
		j--;
		write(1, &hex[j], 1);
	}
	write(1, "\n", 1);
	return (0);
}

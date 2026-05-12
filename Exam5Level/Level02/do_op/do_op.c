/*
Assignment name  : do_op
Expected files   : *.c, *.h
Allowed functions: atoi, printf, write
--------------------------------------------------------------------------------
Write a program that takes three strings:
- The first and the third one are representations of base-10 signed integers
  that fit in an int.
- The second one is an arithmetic operator chosen from: + - * / %

The program must display the result of the requested arithmetic operation,
followed by a newline. If the number of parameters is not 3, the program
just displays a newline.

You can assume the string have no mistakes or extraneous characters. Negative
numbers, in input or output, will have one and only one leading '-'. The
result of the operation fits in an int.
你可以假设字符串中没有错误或多余的字符。输入或输出中的负数都只有一个前导“-”。运算结果可以用整数表示

Examples:
$> ./do_op "123" "*" 456 | cat -e
56088$
$> ./do_op "9828" "/" 234 | cat -e
42$
$> ./do_op "1" "+" "-43" | cat -e
-42$
$> ./do_op | cat -e
$
*/
/*
	从命令行接收两个整数和一个运算符，然后输出计算结果
	程序运行形式：
	./do_op 数字1 运算符 数字2
	例如：
	./do_op "123" "*" 456
	意思是计算：123 * 456， 输出56088

	程序必须接收 3 个参数：
		第一个参数：整数，比如 "123"、"-42"
		第二个参数：运算符，只可能是 + - * / %
		输入保证是合法的，不用检查乱七八糟的字符
		数字和结果都保证能放进 int
		题目没特别说除以 0 怎么办，通常 42 Piscine 的 do_op 会要求除以 0 或取模 0 输出 Stop : division by zero
			/ Stop : modulo by zero，但你贴的版本没有写，所以按题面可以不处理，除非你的测试平台有隐藏要求

	可以用 atoi() 把字符串转成整数，用 printf() 输出结果
*/
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int		x;
	int		y;
	char	operator;
	int		result;

	result = 0;
	if (argc == 4)
	{
		x = atoi(argv[1]);
		y = atoi(argv[3]);
		operator= argv[2][0];
		if (operator == '/' && y == 0)
			printf("NOT take 0 in case of division operation\n");
		else if (operator == '%' && y == 0)
			printf("NOT take 0 in case of modulo operation\n");
		else if (operator == '+')
			result = x + y;
		else if (operator == '-')
			result = x - y;
		else if (operator == '*')
			result = x * y;
		else if (operator == '/')
			result = x / y;
		else if (operator == '%')
			result = x % y;
		printf("%d\n", result);
	}
	else
		printf("\n");
	return (0);
}

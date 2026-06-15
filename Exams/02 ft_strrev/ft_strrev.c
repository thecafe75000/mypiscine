/*
Assignment name  : ft_strrev
Expected files   : ft_strrev.c
Allowed functions:
--------------------------------------------------------------------------------
Write a function that reverses (in-place) a string.
It must return its parameter.

Your function must be declared as follows:
char	*ft_strrev(char *str);

	把传入的字符串原地反转，并返回这个字符串本身
	基本思路是：
		先自己数出字符串长度，找到结尾。
		用两个下标：一个从开头开始，一个从结尾前一个字符开始。
		借助临时变量进行两边字符交换
		左边下标往右走，右边下标往左走，直到相遇
*/

char *ft_strrev(char *str)
{
	int i;
	int j;
	int temp;

	i = 0;
	while (str[i])
		i++;
	j = 0;
	while (j < i)
	{
		temp = str[i - 1];
		str[i - 1] = str[j];
		str[j] = temp;
		j++;
		i--;
	}
	return (str);
}

#include <stdio.h>

int main()
{
	char arr[] = "123abc!*";
	char *result = ft_strrev(arr);
	printf("%s\n", result);
	return (0);
}

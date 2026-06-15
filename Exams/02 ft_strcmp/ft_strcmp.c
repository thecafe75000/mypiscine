/*
Assignment name  : ft_strcmp
Expected files   : ft_strcmp.c
Allowed functions:
--------------------------------------------------------------------------------
Reproduce the behavior of the function strcmp (man strcmp).

Your function must be declared as follows:
int	ft_strcmp(char *s1, char *s2);

	要求实现一个函数，其行为和标准库函数 strcmp 一样
	接收2个字符串，从第1个字符开始逐个比较：
		如果当前字符相同，就继续比较下一个字符
		如果遇到不同字符，就返回它们的 ASCII 值差：s1[i] - s2[i]
		如果两个字符串完全一样，直到 \0 也一样，就返回 0
	注意：返回值重点不是必须是 -1、0、1，而是：
		小于 0：s1 小于 s2
		等于 0：s1 等于 s2
		大于 0：s1 大于 s2
	strcmp 必须比较同一个位置的字符，也就是 s1[i] 和 s2[i]，
	不能用双重循环把 s1 的字符拿去和 s2 的很多位置比较
	strcmp 是逐位同步比较，不是嵌套循环查找相同字符
*/

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	 while (s1[i] && (s1[i] == s2[i]))
		i++;
	return (s1[i] - s2[i]);
}

#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_strcmp("abc", "abc"));
	printf("%d\n", ft_strcmp("abc", "abd"));
	printf("%d\n", ft_strcmp("abd", "abc"));
	printf("%d\n", ft_strcmp("abc", "ab"));
	printf("%d\n", ft_strcmp("ab", "abc"));
	return (0);
}

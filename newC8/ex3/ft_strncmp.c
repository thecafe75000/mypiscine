/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hL <hL@stu.42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 21:16:15 by hL                #+#    #+#             */
/*   Updated: 2026/04/04 11:00:24 by hL               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	按最多前 n 个字符比较两个字符串的函数
	s1：第一个字符串
	s2：第二个字符串
	n：最多比较多少个字符
	返回值：
		< 0：s1 小于 s2
		= 0：二者在比较范围内相等
		> 0：s1 大于 s2
	这里的“小于/大于”本质上是按字符的编码值逐个比较

	strncmp 会从头开始，逐个比较 s1 和 s2 的字符，但有三个停止条件：
		1.已经比较了 n 个字符
		2.发现某一对字符不同
		3.遇到了字符串结束符 '\0'
	只要出现第 2 或第 3 种情况，就会结束比较
*/
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (i < n)
		return (s1[i] - s2[i]);
	return (0);
}

#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*a;
	char	*b;
	char	*c;
	char	*d;
	char	*e;
	char	*f;
	char	*g;

	a = "123";
	b = "123a";
	c = "12";
	d = "";
	e = "abcd";
	f = "ABCD";
	g = "abcd";
	printf("a vs b: %d\n", ft_strncmp(a, b, 4));
	printf("c vs d: %d\n", ft_strncmp(c, d, 1));
	printf("e vs f: %d\n", ft_strncmp(e, f, 4));
	printf("e vs g: %d\n", ft_strncmp(e, g, 4));
	return (0);
}

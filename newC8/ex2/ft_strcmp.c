/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hL <hL@stu.42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 17:00:31 by hL                #+#    #+#             */
/*   Updated: 2026/04/04 10:39:48 by hL               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	strcmp 不是比较“两个指针是不是同一个地址”，而是比较两个字符串，
	从头开始逐个字符一一比较，直到出现不同字符或遇到 '\0' 为止

	strcmp 的返回值不是简单的“true/false”，而是一个整数：
		- 返回 0：说明 s1 和 s2 完全相同
		- 返回 小于 0 的值：说明 s1 小于 s2
		- 返回 大于 0 的值：说明 s1 大于 s2
	这里的“大于/小于”指的是按字符的 ASCII 值逐个比较
*/
/*
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}
*/

int	ft_strcmp(char *s1, char *s2)
{
	char	*s1p;
	char	*s2p;

	s1p = s1;
	s2p = s2;
	while (*s1p && *s2p)
	{
		if (*s1p != *s2p)
			return (*s1p - *s2p);
		s1p++;
		s2p++;
	}
	return (*s1p - *s2p);
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
	c = "ab";
	d = "a1";
	e = "ABCD";
	f = "abcd";
	g = "abcd";
	printf("a vs b: %d\n", ft_strcmp(a, b));
	printf("c vs d: %d\n", ft_strcmp(c, d));
	printf("e vs f: %d\n", ft_strcmp(e, f));
	printf("f vs g: %d\n", ft_strcmp(f, g));
	return (0);
}

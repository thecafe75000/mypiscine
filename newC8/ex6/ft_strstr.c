/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hL <hL@stu.42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 22:17:23 by hL                #+#    #+#             */
/*   Updated: 2026/04/06 23:30:26 by hL               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	在一个字符串中查找另一个子字符串第一次出现位置, 返回子字符串的这个位置，如果找不到返回NULL
*/
char	*ft_strstr(char *str, char *to_find)
{
	char	*strp;
	char	*findp;

	if (*to_find == '\0')
		return (str);
	while (*str)
	{
		strp = str;
		findp = to_find;
		while (*strp && *findp && *strp == *findp)
		{
			strp++;
			findp++;
		}
		if (*findp == '\0')
			return (str);
		str++;
	}
	return (0);
}

#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*src1;
	char	*src2;
	char	*src3;
	char	*src4;

	src1 = "helloParis!";
	src2 = "lloPa";
	src3 = "1234567";
	src4 = "7";
	printf("%p\n", ft_strstr(src1, src2));
	printf("%p\n", strstr(src1, src2));
	printf("%p\n", ft_strstr(src3, src4));
	printf("%p\n", strstr(src3, src4));
	return (0);
}

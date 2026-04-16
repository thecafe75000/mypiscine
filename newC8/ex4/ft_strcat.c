/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hL <hL@stu.42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 19:27:44 by hL                #+#    #+#             */
/*   Updated: 2026/04/04 21:50:41 by hL               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 把 src 指向的字符串内容，复制到 dest 字符串结尾的 '\0' 后面，然后在新的末尾再补一个 '\0'
char	*ft_strcat(char *dest, char *src)
{
	char *destp;

	destp = dest;
	while (*destp)
	{
		destp++;
	}
	while (*src)
	{
		*destp = *src;
		destp++;
		src++;
	}
	*destp = '\0';
	return (dest);
}

#include <stdio.h>

int	main(void)
{
	char dest[20] = "abc123";
	char src[] = "CDE789*!";
	printf("%s\n", ft_strcat(dest, src));
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hL <hL@stu.42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 12:02:53 by hL                #+#    #+#             */
/*   Updated: 2026/04/02 16:30:25 by hL               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	strncpy(dest, src, n) 的行为可以概括为：
		1. 最多从 src 复制 n 个字符到 dest
		2. 如果在复制满 n 个字符之前遇到 src 的结尾字符 '\0'，即当src的字符串长度小于n
		- 那么会把这个src里的 '\0' 也复制过去
		- 然后继续往 dest 后面补 '\0'，直到总共写满 n 个字节
		3. 如果 src 的长度 大于等于 n
		- 那么只复制前 n 个字节
		- 不会自动在 dest 末尾补 '\0'
*/

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	src[] = "abc123";
	char	dest[20];
	char	src1[] = "Paris42here";
	char	dest1[20];
	char	src2[] = "0123456789";
	char	dest2[20];

	printf("src->dest: %s\n", ft_strncpy(dest, src, 4));
	printf("src->dest C: %s\n", strncpy(dest, src, 4));
	printf("src->dest: %s\n", ft_strncpy(dest1, src1, 12));
	printf("src->dest C4: %s\n", strncpy(dest1, src1, 12));
	printf("src->dest9: %s\n", ft_strncpy(dest2, src2, 3));
	printf("src->dest C9: %s\n", strncpy(dest2, src2, 3));
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hL <hL@stu.42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 21:52:51 by hL                #+#    #+#             */
/*   Updated: 2026/04/06 22:15:51 by hL               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	strncat(dest, src, n) 的逻辑可以理解成：
	- 先找到 dest 末尾的 '\0'
	- 从 src 开始复制字符到这个位置, 最多复制 n 个字符
	- 如果 src 在 n 个字符之前就结束了，就提前停止
	- 无论如何，最后都会在结果末尾补一个 '\0'
*/
char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (j < nb && src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

#include <stdio.h>

int	main(void)
{
	char	dest[30] = "abc12";
	char	src[] = "AAAD90*!00000";
	char	dest1[30] = "aabbcc";
	char	src1[] = "789=+hijk";
	char	dest2[30] = "112233";
	char	src2[] = "paris";

	printf("dest: %s\n", ft_strncat(dest, src, 4));
	printf("dest1: %s\n", ft_strncat(dest1, src1, 12));
	printf("dest1: %s\n", ft_strncat(dest2, src2, 0));
	return (0);
}

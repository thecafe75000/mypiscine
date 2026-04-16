/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: string <string>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 12:58:18 by string            #+#    #+#             */
/*   Updated: 2026/03/11 17:11:26 by string           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	c库里的strdup函数原型是 char *strdup(const char *s)
		- s 指向要被复制的原始字符串的指针
		- 成功：返回一个指向新分配内存的指针，该内存包含原始字符串的副本，包括结尾的\0
		- 失败：如果内存分配失败，返回NULL
*/
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	while (src[i])
		i++;
	dest = (char *)malloc((i + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}


#include <stdio.h>

int	main(void)
{
	char	*src;
	char	*dest;

	src = "Hello paris 42";
	dest = ft_strdup(src);
	printf("%s\n", dest);
	free(dest);
	return (0);
}


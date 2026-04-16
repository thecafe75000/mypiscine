/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hL <hL@stu.42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 20:56:53 by hL                #+#    #+#             */
/*   Updated: 2026/04/02 10:37:21 by hL               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
char *ft_strcpy(char *dest, char *src)
{
	char *destpt;
	char *srcpt;

	destpt = dest;
	srcpt = src;
	while (*srcpt)
	{
		*destpt = *srcpt;
		destpt++;
		srcpt++;
	}
	*destpt = '\0';
	return (dest);
}
*/
char *ft_strcpy(char *dest, char *src)
{
	int i;

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
#include <string.h>

int	main()
{
	char a[10] = "abc";
	char adest[10] = "def";
	printf("a->adest: %s\n a->sys: %s\n", ft_strcpy(adest, a), strcpy(adest, a));
	return (0);
}

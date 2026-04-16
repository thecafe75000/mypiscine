/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: string <string>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 10:40:51 by string            #+#    #+#             */
/*   Updated: 2026/03/10 22:29:18 by string           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f)(char *))
{
	if (!tab || !f)
		return (0);
	while (*tab)
	{
		if (f(*tab) > 0)
			return (1);
		tab++;
	}
	return (0);
}
/*
#include <stdio.h>

int	check_letter(char *str)
{
	while (*str)
	{
		if (*str == 'z') // 判断当前字符是不是字母z
			return (1);
		str++;
	}
	return (0);
}

int	main(void)
{
	char	*tab[] = {"abc", "dgfhik", "", "123", "adcqz", "jiplk", NULL};

	printf("%d ", ft_any(tab, check_letter));
	return (0);
}
*/

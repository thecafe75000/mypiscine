/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: string <string>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 21:25:31 by string            #+#    #+#             */
/*   Updated: 2026/03/09 21:27:40 by string           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	if (!*str)
		return (1);
	while (*str)
	{
		if ((*str >= '0' && *str <= '9'))
			str++;
		else
			return (0);
	}
	return (1);
}
/*
#include <stdio.h>

int	main(void)
{
  char arr1[] = "123";
  char arr2[] = "679*976";
  char arr3[] = "123abc";
  char arr4[] = "123\t";

  printf("%d\n", ft_str_is_numeric(arr1));
  printf("%d\n", ft_str_is_numeric(arr2));
  printf("%d\n", ft_str_is_numeric(arr3));
  printf("%d\n", ft_str_is_numeric(arr4));
  return (0);
}
*/

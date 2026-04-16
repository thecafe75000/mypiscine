/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: string <string>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 16:27:56 by string            #+#    #+#             */
/*   Updated: 2026/03/10 10:35:42 by string           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/*
#include <stdio.h>

int	main(void)
{
	char	c1;
	char	c2;

	c1 = 'a';
	c2 = 'K';
	ft_putchar(c1);
	printf("\n");
	ft_putchar(c2);
	return (0);
}
*/

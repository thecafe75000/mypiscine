/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hL <hL@stu.42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 22:30:51 by hL                #+#    #+#             */
/*   Updated: 2026/03/31 13:36:04 by hL               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
int	main(int argc, char **argv)
{
	char	*str;

	(void)argc;
	argv++;
	while (*argv)
	{
		str = *argv;
		while (*str)
		{
			write(1, str, 1);
			str++;
		}
		argv++;
		write(1, "\n", 1);
	}
	return (0);
}
*/

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
	return (0);
}

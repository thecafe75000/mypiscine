/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hL <hL@stu.42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 22:01:47 by hL                #+#    #+#             */
/*   Updated: 2026/03/30 17:54:50 by hL               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
int	main(int argc, char **argv)
{
	if (argc > 0)
	{
		while (*argv[0])
		{
			write(1, argv[0], 1);
			argv[0]++;
		}
		write(1, "\n", 1);
	}
	return (0);
}
*/

// (void)argc 避免未使用参数警告
// 它的作用是：告诉编译器知道 argc 这个参数存在，但故意不使用它
int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	(void)argc;
	while (argv[0][i])
	{
		i++;
	}
	write(1, argv[0], i);
	write(1, "\n", 1);
	return (0);
}

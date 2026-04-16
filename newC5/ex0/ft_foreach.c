/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: string <string>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 16:59:07 by string            #+#    #+#             */
/*   Updated: 2026/03/09 21:14:33 by string           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

/*
	(void*)0 一个通用空指针值, 是一个指向void的空指针，它：
		- 不指向任何对象
		- 不可解引用
		- 可与任意指针类型比较
	NULL 本质上是 (void*)0，任意指针类型都可以和 NULL 比较
 */
// 函数ft_foreach接收一个整型数组、数组长度，以及一个函数指针
// f != 0 等价与 f != NULL，不指向任何函数
void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	if (f != 0 && tab != 0 && length > 0)
	{
		i = 0;
		while (i < length)
		{
			f(tab[i]);
			i++;
		}
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long	x;

	x = nb;
	if (x < 0)
	{
		ft_putchar('-');
		x = -x;
	}
	if (x > 9)
	{
		ft_putnbr(x / 10);
	}
	ft_putchar((x % 10) + '0');
}

// 优化输出打印效果
void	ft_putnbr_space(int n)
{
	ft_putnbr(n);
	ft_putchar(' ');
}

// &ft_putnbr_space 和 ft_putnbr_space 是等价的，函数名本质上是函数地址，
// 编译器自动会把 ft_putnbr_space 转换成 &ft_putnbr_space
/*
int	main(void)
{
	int	tab[] = {-2147483648, -12378, 0, 89679, 888, 876345, 6789, 12, 78678,
			9};

	ft_foreach(tab, 10, ft_putnbr_space);
	printf("\n\n");
	ft_foreach(tab, 10, &ft_putnbr_space);
	return (0);
}
*/

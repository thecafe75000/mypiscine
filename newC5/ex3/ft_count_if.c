/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: string <string>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 22:28:19 by string            #+#    #+#             */
/*   Updated: 2026/03/10 22:56:32 by string           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 创建一个名为 ft_count_if 的函数，该函数会返回数组中通过函数 f 处理后不返回 0 的元素数量
// 26行的 tab[i] 是 char* 类型
int	ft_count_if(char **tab, int length, int (*f)(char *))
{
	int	i;
	int	count;

	if (!tab || length <= 0 || !f)
		return (0);
	i = 0;
	count = 0;
	while (i < length)
	{
		if (f(tab[i]))
			count++;
		i++;
	}
	return (count);
}
/*
#include <stdio.h>

int	check_letter(char *str)
{
	while (*str)
	{
		if (*str == 'c') // 判断当前字符是不是字母z
			return (1);
		str++;
	}
	return (0);
}

#include <stdio.h>

int	main(void)
{
	char	*tab[] = {"abc", "huiop", "123c", "2", "", "opqrst"};

	printf("%d \n", ft_count_if(tab, 6, check_letter));
	return (0);
}
*/

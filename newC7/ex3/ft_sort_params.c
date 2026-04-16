/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hL <hL@stu.42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:06:16 by hL                #+#    #+#             */
/*   Updated: 2026/04/02 10:27:24 by hL               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// 比较的是两个字符串中“对应位置”的字符，一个一个比
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i]) // 只要两个字符串当前字符都没结束,并且这两个字符相同,就继续比较下一位
		i++;
	return (s1[i] - s2[i]);
}

// *a、*b 和 temp 都是指向字符串的指针，交换的是这些指针里保存的地址
void	ft_strswap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

// argv[i] 和 argv[j]都是字符串
int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) > 0)
				ft_strswap(&argv[i], &argv[j]);
			j++;
		}
		while (*argv[i])
		{
			write(1, argv[i], 1);
			argv[i]++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}

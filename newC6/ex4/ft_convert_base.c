/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hL <hL@stu.42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 10:34:06 by hL                #+#    #+#             */
/*   Updated: 2026/07/20 08:12:36 by hL               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		str_length(char *str);
int		check_base(char *base);
int		is_in_base(char c, char *base);

#include <stdlib.h>

int	myatoi(char *str, char *base)
{
	int	sign;
	int	num;
	int	i;

	sign = 1;
	num = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (is_in_base(str[i], base) != -1)
	{
		num = num * check_base(base) + is_in_base(str[i], base);
		i++;
	}
	return (num * sign);
}

// compter la taille d'un int selon notre base
int	nbr_length(int nb, char *base)
{
	int	count;

	count = 0;
	if (nb <= 0)
		count++;
	while (nb != 0)
	{
		nb = nb / check_base(base);
		count++;
	}
	return (count);
}

// converti int en char
char	*my_itoa_base(int num, char *base)
{
	char	*str;
	int		len;

	len = nbr_length(num, base);
	str = malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	len--;
	if (num < 0)
	{
		str[0] = '-';
		num = num * -1;
	}
	if (num == 0)
		str[0] = '0';
	while (num > 0)
	{
		str[len] = base[num % check_base(base)];
		num = num / check_base(base);
		len--;
	}
	return (str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	nb;
	int	len_from;
	int	len_to;

	len_from = check_base(base_from);
	len_to = check_base(base_to);
	if (len_from == 0 || len_to == 0)
		return (0);
	nb = myatoi(nbr, base_from);
	return (my_itoa_base(nb, base_to));
}

#include <stdio.h>

int main(int argc, char **argv)
{
	(void)argc;
	printf("%s\n", ft_convert_base(argv[1], argv[2], argv[3]));
	return (0);
}
/*
void	ft_test(char *nbr, char *base_from, char *base_to)
{
	char	*res;

	res = ft_convert_base(nbr, base_from, base_to);
	printf("nbr       : \"%s\"\n", nbr);
	printf("base_from : \"%s\"\n", base_from);
	printf("base_to   : \"%s\"\n", base_to);
	if (res)
	{
		printf("result    : \"%s\"\n", res);
		free(res);
	}
	else
		printf("result    : NULL\n");
	printf("-----------------------------\n");
}

int	main(void)
{
	ft_test("42", "0123456789", "01");
	ft_test("101010", "01", "0123456789");
	ft_test("52", "01234567", "0123456789");
	ft_test("2a", "0123456789abcdef", "0123456789");
	ft_test("-42", "0123456789", "01");
	ft_test("0", "0123456789", "0123456789abcdef");
	ft_test("-0", "0123456789", "01");
	ft_test("", "0123456789", "01");
	ft_test("   ---42", "0123456789", "01");
	ft_test("42abc", "0123456789", "01");
	ft_test("abc42", "0123456789", "01");
	ft_test(" - 42", "0123456789", "01");
	ft_test("---+     42", "0123456789", "01");
	ft_test("42", "0", "01");
	ft_test("42", "01234056789", "01");
	ft_test("42", "0123456789", "0+1");
	ft_test("0", "0123456789", "12");
	return (0);
}*/

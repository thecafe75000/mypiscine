/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hL <hL@stu.42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 10:34:06 by hL                #+#    #+#             */
/*   Updated: 2026/03/26 16:53:03 by hL               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		check_base(char *base);

// 计算把数字nbr按照base_len进制写出来总共需要几个字符，为申请内存做准备
// 如果是负数，还要额外给负号留一个位置
// 这个函数本质上是在计算：一个数在 base_len 进制下有多少位(即个十百千万这些位数)，就可以通过不断除以 base_len 来计算
int	nbr_len(unsigned long nbr, int neg, int base_len)
{
	int	len;

	len = 1;
	if (neg)
		len++;
	while (nbr >= (unsigned long)base_len)
	{
		nbr = nbr / base_len;
		len++;
	}
	return (len);
}

// 把数字 nbr 转换后的每一位字符，填到结果字符串 res 中
// 这个函数并不负责分配内存，也不负责加 '\0'，它只负责“填内容”
// 用 % base_len 取出最低位, 用 / base_len 去掉最低位, 从字符串末尾往前填入
// base_len：进制长度, digit：当前取出的某一位数字值
// 参数len 是结果字符串的总长度，不是数组大小
void	fill_result(char *res, unsigned long nbr, char *base, int len)
{
	int	base_len;
	int	digit;

	base_len = check_base(base);
	while (nbr > 0)
	{
		digit = nbr % base_len;
		len = len - 1;
		res[len] = base[digit];
		nbr = nbr / base_len;
	}
}

// 完整地把一个long类型整数nbr转换成任意进制字符串，并返回这个字符串
char	*ft_putnbr_base(long nbr, char *base)
{
	char			*res;
	int				len;
	int				base_len;
	unsigned long	nb;
	int				neg;

	base_len = check_base(base);
	neg = (nbr < 0);
	if (neg)
		nb = (unsigned long)(-(nbr + 1)) + 1;
	else
		nb = (unsigned long)nbr;
	len = nbr_len(nb, neg, base_len);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	res[len] = '\0';
	if (nb == 0)
		res[0] = base[0];
	if (neg)
		res[0] = '-';
	fill_result(res, nb, base, len);
	return (res);
}

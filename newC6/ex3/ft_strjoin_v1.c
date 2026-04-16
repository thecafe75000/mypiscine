/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_v1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: string <string>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 22:20:18 by string            #+#    #+#             */
/*   Updated: 2026/03/16 11:54:05 by string           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	把字符串数组 strs 中的所有字符串按顺序用 sep 连接起来，生成一个新的字符串，并返回这个新字符串（该字符串必须是 malloc 分配的）。如果 size == 0，返回一个可 free 的空字符串
	注意：新字符串必须自己分配内存：malloc(最终长度)，需要在 malloc 之前准确计算最终字符串需要多少内存
		 最后一个字符串后面没有分隔符
 */
#include <stdlib.h>

// 计算字符串长度的函数
int	str_length(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int	total_len;
	int	sep_len;
	int	i;
	int	pos;
	int	j;
	int	k;

	if (size == 0)
	{
		result = (char *)malloc(sizeof(char));
		if (!result)
			return (NULL);
		*result = '\0';
		return (result);
	}
	total_len = 0;
	i = 0;
	while (i < size)
	{
		total_len += str_length(strs[i]);
		i++;
	}
	sep_len = str_length(sep);
	total_len += sep_len * (size - 1) + 1;
	result = (char *)malloc(total_len * sizeof(char));
	if (!result)
		return (NULL);
	pos = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			result[pos] = strs[i][j];
			pos++;
			j++;
		}
		if (i < size - 1)
		{
			k = 0;
			while (sep[k] != '\0')
			{
				result[pos] = sep[k];
				pos++;
				k++;
			}
		}
		i++;
	}
	result[pos] = '\0';
	return (result);
}

#include <stdio.h>

int	main(void)
{
	char	*arr1[] = {"Hello", "42 Paris", "C"};
	char	*arr2[] = {""};
	char	*res_output1;
	char	*res_output2;

	res_output1 = ft_strjoin(3, arr1, ", ");
	if (!res_output1)
		printf("null1");
	printf("output: %s\n", res_output1);
	free(res_output1);
	res_output2 = ft_strjoin(0, arr2, ", ");
	if (!res_output2)
		printf("null2");
	printf("output: %s\n", res_output2);
	free(res_output2);
	return (0);
}

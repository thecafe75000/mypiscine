/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: string <string>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 11:53:25 by string            #+#    #+#             */
/*   Updated: 2026/03/16 16:26:39 by string           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	把字符串数组 strs 中的所有字符串按顺序用 sep 连接起来，生成一个新的字符串，并返回这个新字符串（该字符串必须是 malloc 分配的）。如果 size == 0，返回一个可 free 的空字符串
	注意：新字符串必须自己分配内存：malloc(最终长度)，需要在 malloc 之前准确计算最终字符串需要多少内存
			最后一个字符串后面没有分隔符
 */
#include <stdlib.h>

// 计算单个字符串长度的函数
int	str_length(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

// 处理空字符串，即当size == 0时的情况
char	*ft_emptystr(void)
{
	char	*result;

	result = (char *)malloc(1 * sizeof(char));
	if (!result)
		return (NULL);
	*result = '\0';
	return (result);
}

// 计算合并后新字符串的长度
int	ft_totallen(int size, char **strs, char *sep)
{
	int	total_len;
	int	sep_len;
	int	i;

	total_len = 0;
	sep_len = str_length(sep);
	i = 0;
	while (i < size)
	{
		while (i < size)
		{
			total_len += str_length(strs[i]);
			i++;
		}
		sep_len = str_length(sep);
		total_len += sep_len * (size - 1) + 1;
	}
	return (total_len);
}

// 拷贝字符串到目标数组里, 从数组下标pos开始，返回新的下标
int	ft_copystr(char *dest, char *str, int pos)
{
	int	i;

	i = 0;
	while (str[i])
	{
		dest[pos] = str[i];
		pos++;
		i++;
	}
	return (pos);
}

// 拷贝分隔符到目标数组里, 从数组下标pos开始，返回新的下标位置
int	ft_copysep(char *dest, char *sep, int pos)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		dest[pos] = sep[i];
		pos++;
		i++;
	}
	return (pos);
}

// 参数char **strs 表示要接收多个字符串，即接收字符串数组
char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		total_len;
	int		pos;
	int		i;

	if (size == 0)
		ft_emptystr();
	total_len = ft_totallen(size, strs, sep);
	result = (char *)malloc(total_len * sizeof(char));
	if (!result)
		return (NULL);
	pos = 0;
	i = 0;
	while (i < size)
	{
		pos = ft_copystr(result, strs[i], pos);
		if (i < size - 1)
			pos = ft_copysep(result, sep, pos);
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
	char	*arr3[] = {"abcefg123", "Hi"};
	char	*res_output1;
	char	*res_output2;
	char	*res_output3;

	res_output1 = ft_strjoin(3, arr1, " - ");
	if (!res_output1)
		printf("null1");
	printf("output: %s\n", res_output1);
	free(res_output1);
	res_output2 = ft_strjoin(0, arr2, ", ");
	if (!res_output2)
		printf("null2");
	printf("output: %s\n", res_output2);
	free(res_output2);
	res_output3 = ft_strjoin(2, arr3, " * ");
	if (!res_output3)
		printf("null3");
	printf("output: %s\n", res_output3);
	free(res_output3);
	return (0);
}

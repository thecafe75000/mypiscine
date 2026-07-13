/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hL <hL@stu.42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 22:20:18 by string            #+#    #+#             */
/*   Updated: 2026/07/13 21:40:26 by hL               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	把字符串数组 strs 中的所有字符串按顺序用 sep 连接起来，生成一个新的字符串，并返回这个新字符串（该字符串必须是 malloc 分配的）。如果 size == 0，返回一个可 free 的空字符串
	注意：新字符串必须自己分配内存：malloc(最终长度)，需要在 malloc 之前准确计算最终字符串需要多少内存，最后一个字符串后面没有分隔符
	ft_strjoin就是把一个字符串数组 (char **strs) 中的所有字符串，用指定的分隔符 (sep) 连接起来，返回一个新字符串

	参数：
		- size 表示有几个字符串
		- char **strs 表示字符串数组
		- char *sep 表示分隔符

	举例：
		char *strs[] =
		{
			"apple",
			"banana",
			"orange"
		};

		sep = "---"
	函数应该返回：apple---banana---orange
 */
#include <stdlib.h>

// 计算一个字符串长度
int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

// 计算整个字符串数组所有字符串长度总和
int	ft_strslen(char **strs, int size)
{
	int	i;
	int	lens;

	i = 0;
	lens = 0;
	while (i < size)
	{
		lens += ft_strlen(strs[i]);
		i++;
	}
	return (lens);
}
// 复制字符串（不复制 '\0'）
void	ft_strcpy(char *dest, char *src)
{
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
}
// 把所有字符串依次复制到 result 中
void	ft_join(char *result, int size, char **strs, char *sep)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_strcpy(result, strs[i]);
		result += ft_strlen(strs[i]);
		if (i != size - 1) // 最后一个字符串后面不能再加分隔符,因此要size-1
		{
			ft_strcpy(result, sep);
			result += ft_strlen(sep);
		}
		i++;
	}
	*result = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;

	if (size == 0)
	{
		result = (char *)malloc(1 * sizeof(char));
		*result = '\0';
		return (result);
	}
	result = (char *)malloc((ft_strslen(strs, size) + (ft_strlen(sep) * (size
						- 1)) + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	ft_join(result, size, strs, sep);
	return (result);
}

#include <stdio.h>

void	ft_strjoin_test(char *test[])
{
	char	*output;

	output = ft_strjoin(0, test, ",");
	printf("test0:\n%s\n", output);
	free(output);
	output = ft_strjoin(0, test, "");
	printf("test1:\n%s\n", output);
	free(output);
	output = ft_strjoin(0, test, "-----");
	printf("test2:\n%s\n", output);
	free(output);
	output = ft_strjoin(5, test, ",");
	printf("test3:\n%s\n", output);
	free(output);
	output = ft_strjoin(5, test, "");
	printf("test4:\n%s\n", output);
	free(output);
	output = ft_strjoin(5, test, "-----");
	printf("test5:\n%s\n", output);
	free(output);
	output = ft_strjoin(2, test, ",");
	printf("test6:\n%s\n", output);
	free(output);
	output = ft_strjoin(2, test, "");
	printf("test7:\n%s\n", output);
	free(output);
	output = ft_strjoin(2, test, "-----");
	printf("test8:\n%s\n", output);
	free(output);
	printf("===============\n");
}

int	main(void)
{
	char	*test0[] = {"head", "...", "next is empty", "", "this end"};
	char	*test1[] = {""};
	char	*test2[] = {"1adfaeg68a4eg"};

	ft_strjoin_test(test0);
	ft_strjoin_test(test1);
	ft_strjoin_test(test2);
}

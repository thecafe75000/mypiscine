/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hL <hL@stu.42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 15:11:30 by hL                #+#    #+#             */
/*   Updated: 2026/03/27 16:28:16 by hL               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 题目要求：
	把字符串 str 按照 charset 中的任意字符进行切分，得到若干个非空单词，
	最后返回一个以 NULL 结尾的字符串数组
*/
#include <stdlib.h>

// 判断当前字符是不是charset里的分隔符
int	is_separator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

// 计算为数组申请多大的内存
// if 判断：判断当前字符是不是一个新单词的开头，如果是就count++
int	count_words(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (!is_separator(str[i], charset) && (i == 0 || is_separator(str[i
					- 1], charset)))
			count++;
		i++;
	}
	return (count);
}

// 获取当前单词的长度
int	word_len(char *str, char *charset)
{
	int	len;

	len = 0;
	while (str[len] && !is_separator(str[len], charset))
		len++;
	return (len);
}
// 把当前单词从原字符串里复制出来
char	*copy_word(char *str, char *charset)
{
	int		len;
	int		i;
	char	*word;

	len = word_len(str, charset);
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

// 负责总调度
char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	char	**result;

	result = (char **)malloc(sizeof(char) * (count_words(str, charset) + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && is_separator(str[i], charset))
			i++;
		if (str[i])
		{
			result[j] = copy_word(&str[i], charset);
			j++;
			i += word_len(&str[i], charset);
		}
	}
	result[j] = NULL;
	return (result);
}

#include <stdio.h>

void	ft_split_test(char *str, char *charset)
{
	char	**result;
	int		i;

	result = ft_split(str, charset);
	i = 0;
	while (result[i])
	{
		printf("%s\n", result[i]);
		if (result[i])
			free(result[i]);
		i++;
	}
	printf("================\n");
}

int	main(void)
{
	ft_split_test("abc,def-ggg#123", ",-#");
	ft_split_test("abc,def.lll!123", ",.!");
	ft_split_test("abc,def..!!123", ",.!");
	ft_split_test("abc,def..!!123", "$");
	ft_split_test(",..!!", ",.!");
	ft_split_test(",..!!", "");
	ft_split_test("", ",.!");
	ft_split_test("abc,def..!!123", "bc,def..!!12");
	ft_split_test("abc,def..!!123", "abc,def..!!12");
	ft_split_test("abc,def..!!123", "bc,def..!!123");
	ft_split_test("abc,def..!!123", "abc,def..!!123");
	return (0);
}


/* 题目要求：
	把字符串 str 按照 charset 中的任意字符进行切分，得到若干个非空单词，
	最后返回一个以 NULL 结尾的字符串数组
*/
#include <stdlib.h>

// 判断当前字符是不是charset里的分隔符
int	in_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}
// 统计字符串里有多少个单词
int	count_substr(char *str, char *charset)
{
	int	i;
	int	count;
	int	range[2];

	i = 0;
	count = 0;
	range[0] = -1;
	while (str[i])
	{
		if (in_charset(str[i], charset))
		{
			range[1] = i;
			if (range[1] - range[0] > 1)
				count++;
			range[0] = range[1];
		}
		i++;
	}
	if (i - range[0] > 1)
		count++;
	return (count);
}
// 复制一个单词，start 表示的是前一个分隔符的位置，真正复制从 start + 1 开始
int	get_substr(char **substr, char *str, int start, int end)
{
	int	i;

	if (end - start < 1)
		return (0);
	*substr = (char *)malloc((end - start) * sizeof(char));
	if (!*substr)
		return (-1);
	i = 0;
	while (i + (start + 1) < end)
	{
		(*substr)[i] = str[i + (start + 1)];
		i++;
	}
	(*substr)[i] = '\0';
	return (i);
}

// 循环提取所有单词
int	get_all_substrs(char **result, char *str, char *charset)
{
	int	range[2];
	int	count;

	range[0] = -1;
	range[1] = 0;
	count = 0;
	while (str[range[1]])
	{
		if (in_charset(str[range[1]], charset))
		{
			if (range[1] - range[0] > 1 && get_substr(&(result[count++]), str,
					range[0], range[1]) == -1)
				return (-1);
			range[0] = range[1];
		}
		range[1]++;
	}
	if (range[1] - range[0] > 1 && get_substr(&(result[count++]), str, range[0],
			range[1]) == -1)
		return (-1);
	result[count] = NULL;
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	int		substr_count;
	char	**reslut;

	substr_count = count_substr(str, charset);
	reslut = (char **)malloc((substr_count + 1) * sizeof(char *));
	if (reslut == NULL)
		return (NULL);
	if (!*str || substr_count == 0)
	{
		reslut[0] = NULL;
		return (reslut);
	}
	if (get_all_substrs(reslut, str, charset) == -1)
		return (NULL);
	return (reslut);
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
	free(result);
	printf("====================\n");
}

int	main(void)
{
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
}

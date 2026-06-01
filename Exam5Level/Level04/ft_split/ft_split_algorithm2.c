/*
	这版在split函数里使用了free
*/

#include <stdlib.h>

static int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

// 统计字符串里有几个单词, 即有几个子串
static int	count_words(char *str)
{
	int	count;
	int	i;
	int	is_in_word;

	count = 0;
	i = 0;
	is_in_word = 0;
	while (str[i])
	{
		// 当前扫描状态在单词内部，但当前字符是分隔符,说明扫描了一个完整的单词
		// 扫描一个单词结束时，单词的数量就可以计数
		if (is_in_word && is_space(str[i]))
		{
			count++;
			is_in_word = 0;
		}
		else if (!is_in_word && !is_space(str[i])) // 开始一个新单词
			is_in_word = 1;
		i++;
	}
	if (is_in_word) // 处理字符串结尾, 最后一个单词扫描完要计数
		count++;
	return (count);
}

// 获取单个单词的长度
// 第2个参数i是单词的起始位置，因为字符串里的单词是从任意位置开始
static int	get_word_len(char *str, int i)
{
	int	len;

	len = 0;
	while (str[i] && !is_space(str[i]))
	{
		i++;
		len++;
	}
	return (len);
}

static void	free_all(char **result, int i)
{
	while (i > 0)
	{
		free(result[i]);
		i--;
	}
	free(result);
}

char	**ft_split(char *str)
{
	char	**result;
	int		wordsnum;
	int		word_len;
	int		i;
	int		j;
	int		k;
	int		start;

	if (!str)
		return (NULL);
	wordsnum = count_words(str);
	result = malloc(sizeof(char *) * (wordsnum + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	// 开始扫描整个字符串
	while (str[i])
	{
		// 跳过分隔符
		while (str[i] && is_space(str[i]))
			i++;
		if (str[i]) // 说明字符串还没走到'\0', 开始扫描单词
		{
			start = i;
			word_len = get_word_len(str, i);
			result[j] = malloc(sizeof(char) * (word_len + 1));
			if (!result[j])
			{
				free_all(result, j - 1);
				return (NULL);
			}
			k = 0;
			// 复制单词，即逐个复制单词的每一个字符
			while (k < word_len)
			{
				result[j][k] = str[start + k];
				k++;
			}
			result[j][k] = '\0';
			j++;
			// 跳过当前已经扫描过的单词
			i += word_len;
		}
	}
	result[j] = NULL;
	return (result);
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	char	**strs;
	int		i;

	if (argc != 2)
	{
		printf("error in parameters\n");
		return (1);
	}
	strs = ft_split(argv[1]);
	i = 0;
	while (strs != NULL && strs[i] != NULL)
	{
		printf("%d:%s\n", i, strs[i]);
		i++;
	}
	free(strs);
	return (0);
}

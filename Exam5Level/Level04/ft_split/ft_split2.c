/*
Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------
Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.
A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:
char	**ft_split(char *str);

例如：
	ft_split("  hello\tworld\n42  ")
	应该返回：[
				"hello",
				"world",
				"42",
				NULL
			]
*/

#include <stdio.h>
#include <stdlib.h>

int	is_separator(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

// 计算有几个子串
int	get_sub_str_count(char *str)
{
	int	i;
	int	in_word;
	int	count;

	i = 0;
	count = 0;
	in_word = 0;
	while (str[i])
	{
		if (in_word && is_separator(str[i]))
		{
			count++;
			in_word = 0;
		}
		else if (!in_word && !is_separator(str[i]))
			in_word = 1;
		i++;
	}
	if (in_word)
		count++;
	return (count);
}

char	*put_sub_str(char *str, int n)
{
	int		is_in_word;
	int		index;
	int		i;

	// find sub_str start
	int start;
	int end;
	index = 0;
	is_in_word = 0;
	start = 0;
	while (str[start])
	{
		if (is_in_word && is_separator(str[start]))
		{
			index++;
			is_in_word = 0;
		}
		else if (!is_in_word && !is_separator(str[start]))
		{
			is_in_word = 1;
			if (n == index)
				break ;
		}
		start++;
	}
	if (!str[start])
		return (NULL);

	// find sub_str end
	end = start;
	while (str[end])
	{
		if (is_separator(str[end]))
			break ;
		end++;
	}
	// copy sub_str
	i = start;
	while (i < end)
	{
		printf("%c", str[i]);
		i++;
	}
	return (str);
}

char	*get_sub_str(char *str, int n)
{
	int		is_in_word;
	int		index;
	int		sub_str_len;
	char	*sub_str;
	int		i;

	// find sub_str start
	int start;
	int end;
	index = 0;
	is_in_word = 0;
	start = 0;
	while (str[start])
	{
		if (is_in_word && is_separator(str[start]))
		{
			index++;
			is_in_word = 0;
		}
		else if (!is_in_word && !is_separator(str[start]))
		{
			is_in_word = 1;
			if (n == index)
				break ;
		}
		start++;
	}
	if (!str[start])
		return NULL;
	// find sub_str end
	end = start;
	while (str[end])
	{
		if (is_separator(str[end]))
			break ;
		end++;
	}
	// copy sub_str
	sub_str_len = end - start;
	sub_str = malloc(sizeof(char) * (sub_str_len + 1));
	if (sub_str == NULL)
		return (NULL);
	i = 0;
	while ((i + start) < end)
	{
		sub_str[i] = str[i + start];
		i++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}

char	**ft_split(char *str)
{
	char	**result;
	int		i;
	int		sub_str_count;

	if (str == NULL || *str == '\0')
		return (NULL);
	sub_str_count = get_sub_str_count(str);
	result = malloc(sizeof(char *) * (sub_str_count + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < sub_str_count)
	{
		result[i] = get_sub_str(str, i);
		if (result[i] == NULL)
		{
			while (i > 0)
			{
				i--;
				free(result[i]);
			}
			free(result);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}

int	main(int argc, char **argv)
{
	char	**strs;
	int		i;

	if (argc != 2)
		return (1);
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

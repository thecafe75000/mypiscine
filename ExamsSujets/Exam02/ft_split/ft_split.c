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
*/
#include <stdlib.h>

int is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int count_word(char *str)
{
	int i;
	int count;
	int is_in_word;

	i = 0;
	count = 0;
	is_in_word = 0;
	while (str[i])
	{
		if (is_space(str[i]) && is_in_word)
		{
			count++;
			is_in_word = 0;
		}
		else if(!is_in_word && is_space(str[i]))
			is_in_word = 1;
		i++;
	}
	if (is_in_word)
		count++;
	return (count);
}

int get_word_len(char *str, int pos)
{
	int len;

	len = 0;
	while (str[pos] && is_space(str[pos]))
	{
		pos++;
		len++;
	}
	return (len);
}

char	**ft_split(char *str)
{

}

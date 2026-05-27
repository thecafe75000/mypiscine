
#include <stdlib.h>

char	**ft_split(char *str)
{
	int		i;
	int		j;
	int		k;
	int		start;
	int		count;
	char	**result;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if (str[i])
			count++;
		while (str[i] && !(str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
	}
	result = malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		start = i;
		while (str[i] && !(str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if (i > start)
		{
			result[j] = malloc(sizeof(char) * (i - start + 1));
			if (!result[j])
				return (NULL);
			k = 0;
			while (start + k < i)
			{
				result[j][k] = str[start + k];
				k++;
			}
			result[j][k] = '\0';
			j++;
		}
	}
	result[j] = NULL;
	return (result);
}

#include <stdio.h>

int	main(void)
{
	char	*str;
	char	**result;
	int		i;

	str = "  Welcome to Ganton en Chine !";
	result = ft_split(str);
	i = 0;
	while (result[i])
	{
		printf("result[%d] = %s\n", i, result[i]);
		i++;
	}
	printf("result[%d] = NULL\n", i);
	return (0);
}

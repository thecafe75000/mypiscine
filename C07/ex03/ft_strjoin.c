
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

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

void	ft_strcpy(char *dest, char *src)
{
	while (*src)
		*dest++ = *src++;
}

void	ft_join(char *result, int size, char **strs, char *sep)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_strcpy(result, strs[i]);
		result += ft_strlen(strs[i]);
		if (i != size - 1)
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
	result = (char *)malloc((ft_strslen(strs, size)
				+ (ft_strlen(sep) * (size - 1)) + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	ft_join(result, size, strs, sep);
	return (result);
}
/*
#include <stdio.h>

void	ft_strjoin_test(char *test[])
{
	char *output = ft_strjoin(0, test, ",");
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
	char *test0[] = {"head", "...", "next is empty", "", "this end"};
	char *test1[] = {""};
	char *test2[] = {"1adfaeg68a4eg"};

	ft_strjoin_test(test0);
	ft_strjoin_test(test1);
	ft_strjoin_test(test2);
}
*/

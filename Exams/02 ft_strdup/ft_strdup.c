/*
Assignment name  : ft_strdup
Expected files   : ft_strdup.c
Allowed functions: malloc
--------------------------------------------------------------------------------
Reproduce the behavior of the function strdup (man strdup).

Your function must be declared as follows:
char	*ft_strdup(char *src);

	char *strdup(const char *s) 是 C 库中的字符串复制函数
	它的作用是分配足够的内存，并把字符串 s 复制进去，然后返回新字符串的地址
*/

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		len;
	char	*newstr;
	int		i;

	len = 0;
	while (src[len])
		len++;
	newstr = malloc(sizeof(char) * (len + 1));
	if (!newstr)
		return (NULL);
	i = 0;
	while (src[i])
	{
		newstr[i] = src[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

#include <stdio.h>
#include <string.h>

int	main(void)
{
	char *src = "abcHello42!";
	char *dest1 = ft_strdup(src);
	printf("dest1: %s\n", dest1);
	char *dest2 = strdup(src);
	printf("dest2: %s\n", dest2);
	free(dest1);
	free(dest2);
	return (0);
}

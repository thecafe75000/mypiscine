/*
Assignment name  : ft_strdup
Expected files   : ft_strdup.c
Allowed functions: malloc
--------------------------------------------------------------------------------
Reproduce the behavior of the function strdup (man strdup).

Your function must be declared as follows:
char	*ft_strdup(char *src);
*/
/*
	char *strdup(const char *s) 是 C 库中的字符串复制函数
	它的作用是分配足够的内存，并把字符串 s 复制进去，然后返回新字符串的地址
*/

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int length;
	char *dest;
	int i;

	length = 0;
	while (src[length])
	{
		length++;
	}
	dest = malloc(sizeof(char) * (length + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

#include <stdio.h>

int	main(void)
{
	char	*src = "abcHello42!";
	char 	*dest = ft_strdup(src);
	printf("dest: %s\n", dest);
	free(dest);
	char *src2 = "123 abc  Hello42!";
	char 	*dest2 = ft_strdup(src2);
	printf("dest2: %s\n", dest2);
	free(dest2);
	char *empty = "";
	char *copy = ft_strdup(empty);
	printf("empty: %s\n", copy);
	return (0);
}

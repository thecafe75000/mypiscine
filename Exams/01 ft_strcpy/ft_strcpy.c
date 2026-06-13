/*
Assignment name  : ft_strcpy
Expected files   : ft_strcpy.c
Allowed functions:
--------------------------------------------------------------------------------
Reproduce the behavior of the function strcpy (man strcpy).

Your function must be declared as follows:
char	*ft_strcpy(char *s1, char *s2);

	把 s2 字符串的内容复制到 s1 里
	包括最后那个字符串结束符 '\0' 也会一起复制
*/

char	*ft_strcpy(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

#include <stdio.h>
#include <string.h>

int main()
{
	char dest[20];
	char src[] = "1234567890abcde!*";
	if (strlen(src) + 1 > sizeof(dest))
	{
		printf("error");
		return (0);
	}
	printf("%s\n", ft_strcpy(dest, src));
	return (0);
}

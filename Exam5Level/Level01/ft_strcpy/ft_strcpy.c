/*
Assignment name  : ft_strcpy
Expected files   : ft_strcpy.c
Allowed functions:
--------------------------------------------------------------------------------
Reproduce the behavior of the function strcpy (man strcpy).

Your function must be declared as follows:
char	*ft_strcpy(char *s1, char *s2);
*/

char	*ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (s2[i] == '\0')
		return (0);
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

#include <stdio.h>

int	main(void)
{
	char	s1[30];
	char	s2[] = "123abc*!CD";

	ft_strcpy(s1, s2);
	printf("%s\n", s1);
	printf("%s\n", ft_strcpy(s1, s2));
	return (0);
}

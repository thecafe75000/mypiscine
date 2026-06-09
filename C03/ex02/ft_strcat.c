
char	*ft_strcat(char *dest, char *src)
{
	char	*origin;

	origin = dest;
	while (*dest)
		dest++;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (origin);
}
/*
#include <stdio.h>
#include <string.h>

void strcat_test(char* a, char* b)
{
	printf("%s + %s =\nft_: %s\nsys: %s\n\n",
		a, b, ft_strcat(a, b), strcat(a, b));
}

int	main(void)
{
	char a[50] = "abc";
	char b[50] = "0123";
	char c[50] = "";

	strcat_test(a, b);
	strcat_test(b, a);
	strcat_test(c, a);
	strcat_test(a, c);
}
*/

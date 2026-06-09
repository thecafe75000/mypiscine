
char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char			*origin;
	unsigned int	i;

	i = 0;
	origin = dest;
	while (*dest)
		dest++;
	while (*src && i < nb)
	{
		*dest = *src;
		dest++;
		src++;
		i++;
	}
	*dest = '\0';
	return (origin);
}
/*
#include <stdio.h>
#include <string.h>

void strncat_test(char* a, char* b, char* aa, char* bb, int n)
{
	printf("ft_: %s + %s (%d) =\n\t%s\n", a, b, n, ft_strncat(a, b, n));
	printf("sys: %s + %s (%d) =\n\t%s\n\n", aa, bb, n, ft_strncat(aa, bb, n));
}

int	main(void)
{
	char a[50] = "abc";
	char b[50] = "0123";
	char c[50] = "";
	char aa[50] = "abc";
	char bb[50] = "0123";
	char cc[50] = "";

	strncat_test(a, b, aa, bb, 0);
	strncat_test(a, b, aa, bb, 1);
	strncat_test(b, a, bb, aa, 2);
	strncat_test(c, a, cc, aa, 3);
	strncat_test(a, c, aa, cc, 4);
	strncat_test(a, c, aa, cc, 20);
}
*/


unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	srclen;

	srclen = 0;
	while (src[srclen])
		srclen++;
	if (size == 0)
		return (srclen);
	i = 0;
	while (src[i] != '\0' && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (srclen);
}
/*
#include <stdio.h>
#include <string.h>
#include <bsd/string.h>

void strlcpy_test(char* dest, char* dest2, char* src)
{
	printf("%s -%lu-> %s\n", src, sizeof(dest), dest);
	unsigned int ft = ft_strlcpy(dest, src, sizeof(dest));
	printf("(%d), %s\n", ft, dest);
	printf("%s -%lu-> %s\n", src, sizeof(dest2), dest2);
	size_t sys = strlcpy(dest2, src, sizeof(dest));
	printf("(%zu), %s\n\n", sys, dest2);
}

int	main(void)
{
	char a[5] = "abc",
		aa[5] = "abc",
		 b[50] = "Paris",
		 c[50] = "0123456789",
		 d[50] = "";

	strlcpy_test(a, aa, b);
	strlcpy_test(a, aa, c);
	strlcpy_test(a, aa, d);
}
*/

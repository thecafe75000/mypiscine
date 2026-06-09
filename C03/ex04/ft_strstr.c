
char	*ft_strstr(char *dest, char *to_find)
{
	char	*subdest;
	char	*subfind;

	if (*to_find == '\0')
		return (dest);
	while (*dest)
	{
		subdest = dest;
		subfind = to_find;
		while (*subdest && *subfind && *subdest == *subfind)
		{
			subdest++;
			subfind++;
		}
		if (*subfind == '\0')
			return (dest);
		dest++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

void	strstr_test(char* dest, char* to_find)
{
	printf("d:%s\nf:%s\nft_:%s\nsys:%s\n\n",
		dest, to_find, ft_strstr(dest, to_find), strstr(dest, to_find));
}

int	main(void)
{
	char *a = "abcdefghijklmnopqrstuvwxyz0123456789",
		 *b = "a",
		 *c = "0",
		 *d = "",
		 *e = "opqrstuv",
		 *f = "10",
		 *g = "9";
	strstr_test(a, b);
	strstr_test(a, c);
	strstr_test(a, d);
	strstr_test(a, e);
	strstr_test(a, f);
	strstr_test(a, g);
}
*/

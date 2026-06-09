
int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
/*
#include <stdio.h>
#include <string.h>

void strcmp_test(char* a, char* b)
{
	printf("%s:%s %d,%d\n", a, b, ft_strcmp(a, b), strcmp(a, b));
}

int	main(void)
{
	char *a = "123";
	char *b = "123a";
	char *c = "12";
	char *d = "";
	char *e = "abc";
	char *f = "ABC";

	strcmp_test(a, b);
	strcmp_test(a, c);
	strcmp_test(a, d);
	strcmp_test(a, e);
	strcmp_test(a, f);
	strcmp_test(e, f);
}
*/

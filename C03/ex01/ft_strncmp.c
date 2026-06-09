
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	char			*p1;
	char			*p2;
	unsigned int	i;

	if (n == 0)
		return (0);
	p1 = s1;
	p2 = s2;
	i = 0;
	while (i < n && p1[i] && p2[i])
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	if (i < n)
		return (p1[i] - p2[i]);
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

void strncmp_test(char* a, char* b, int n)
{
	printf("%s:%s,%d | %d,%d\n",
		a, b, n, ft_strncmp(a, b, n), strncmp(a, b, n));
}

int	main(void)
{
	char *a = "123";
	char *b = "123a";
	char *c = "12";
	char *d = "";
	char *e = "abc";
	char *f = "ABC";
	// same with strcmp
	strncmp_test(a, b, 10);
	strncmp_test(a, c, 10);
	strncmp_test(a, d, 10);
	strncmp_test(a, e, 10);
	strncmp_test(a, f, 10);
	strncmp_test(e, f, 10);
	// short&empty case
	strncmp_test(a, b, 4);
	strncmp_test(a, b, 3);
	strncmp_test(a, b, 2);
	strncmp_test(a, b, 1);
	strncmp_test(a, b, 0);
	strncmp_test(a, d, 0);
	strncmp_test(d, a, 0);
	strncmp_test(a, d, 2);
	strncmp_test(d, a, 2);
}
*/

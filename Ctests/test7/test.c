#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 函数指针和字符串
int	compare(const char *s1, const char *s2)
{
	return (strcmp(s1, s2));
}

char	*stringToLower(const char *string)
{
	char	*tmp;
	char	*start;

	tmp = (char *)malloc(strlen(string) + 1);
	start = tmp;
	while (*string != 0)
	{
		*tmp++ = tolower(*string++);
	}
	*tmp = 0;
	return (start);
}

int	compareCase(const char *s1, const char *s2)
{
	char	*t1;
	char	*t2;
	int		result;

	t1 = stringToLower(s1);
	t2 = stringToLower(s2);
	result = strcmp(t1, t2);
	free(t1);
	free(t2);
	return (result);
}

int	main(void)
{
	char	s1[] = "hello";
	char	s2[] = "abc";
	int		rescompare;
	int		resultComp;
	char name[] = "Bob";
	char nom[] = "Benjamain";

	rescompare = compare(s1, s2);
	printf("rescompare = %d", rescompare);
	printf("\n");
	if (rescompare > 0)
	{
		printf("s1 > s2");
	}
	else if (rescompare == 0)
	{
		printf("s1 == s2");
	}
	else
	{
		printf("s1 < s2");
	}
	printf("\n");
	resultComp = compareCase(name, nom);
	printf("resultComp = %d\n", resultComp);
	printf("\n");
	return (0);
}

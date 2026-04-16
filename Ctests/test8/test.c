#include <stdio.h>

void	change(int *p)
{
	int	a;

	a = 100;
	p = &a;
	printf("*p in change function= %d\n", *p);
}

void	change2(int **p)
{
	**p = 900;
	printf("**p in change2 function= %d\n", **p);
}

int	main(void)
{
	int	x;
	int	*p;

	x = 10;
	p = &x;
	change(p);
	printf("*p= %d\n", *p);
	printf("x = %d\n", x);
	change2(&p);
	printf("*p= %d\n", *p);
	printf("x = %d\n", x);
	return (0);
}

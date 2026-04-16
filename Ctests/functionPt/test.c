#include <stdio.h>
#include <stdlib.h>
typedef int (*fptsum)(int, int);

int	square(int num)
{
	return (num * num);
}

int	sum(int a, int b)
{
	return a + b;
}
int	main(void)
{
	int	(*fptsquare)(int); // 函数指针
	fptsquare = square; // 函数指针指向函数square
	printf("result square = %d \n", fptsquare(5));

	fptsum fpt;
	fpt = sum;
	printf("result sum = %d \n", fpt(10, 80));

	return (0);
}

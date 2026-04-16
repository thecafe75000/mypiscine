#include <stdio.h>
#include <stdlib.h>

void	fn(int *p)
{
	*p = 100;
}

int	*allocateArray(int size, int value)
{
	int	*arr;

	if (size <= 0)
		return (NULL);
	arr = (int *)malloc(size * sizeof(int));
	if (!arr)
		return (NULL);
	for (int i = 0; i < size; i++)
	{
		arr[i] = value;
	}
	return (arr); // 通过“返回值”把指针传回调用者
}

int	main(void)
{
	int	a;
	int	*vector;
	int	arr[] = {1, 2, 3, 4, 5};

	a = 6;
	printf("before a = %d\n", a);
	fn(&a);
	printf("after a = %d\n", a);
	vector = allocateArray(5, 45);
	if (!vector)
		return (1);
	for (int i = 0; i < 5; i++)
	{
		printf("vector[%d] = %d ", i, vector[i]);
	}
	free(vector);
	printf("\n");
	printf("arr= %p\n", arr);
	printf("&arr= %p\n", &arr);
	printf("&arr[0]= %p\n", &arr[0]);
	printf("arr + 1= %p\n", arr + 1);
	printf("&arr + 1= %p\n", &arr + 1);
	return (0);
}

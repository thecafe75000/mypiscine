#include <stdio.h>
#include <stdlib.h>

// 通过“二级指针参数”在函数内部修改调用者的指针
void	allocateArray(int **arr, int size, int value)
{
	*arr = (int *)malloc(size * sizeof(int));
	if (*arr != NULL)
	{
		for (int i = 0; i < size; i++)
		{
			*(*arr + i) = value;
		}
	}
}

int	main(void)
{
	int	*vector;

	vector = NULL;
	allocateArray(&vector, 5, 45);
	for (int i = 0; i < 5; i++)
	{
		printf("vector[%d] = %d ", i, vector[i]);
	}
	return (0);
}

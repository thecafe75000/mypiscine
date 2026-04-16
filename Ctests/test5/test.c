#include <stdio.h>
#include <stdlib.h>

/*
	一维数组作为函数的参数进行传递
*/
void	displayArray(int arr[], int size)
{
	printf("value of every element = ");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
}

void	displayArray2(int *arr, int size)
{
	printf("value of every element2 = ");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	printf("value of every element2 = ");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", *(arr + i));
	}
	printf("\n");
}
// 使用指针数组，即每个元素都是一个指针，即地址
void	displayArray3(int **arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		/*
			arr + i 是第 i 个数组元素的地址，类型仍然是 int **
			代码 *(arr + i) = malloc(...) 意思是 让 arr[i] 指向这块新内存
			且 *(arr + i) 是 第 i 个 int * 元素，也就是 arr[i]，是内存地址，malloc 返回的指针
			所以 **(arr + i) 等价于 *arr[i] → 获取内存里的整数
			关系理解：
				1. main 的 arr 是一个固定大小的指针数组
				2. 调用函数时，arr 数组名 → 退化成指向首元素的指针 → int **
				3. 函数内通过 *(arr + i) 或 arr[i] 修改了 原数组的元素值
				4. 因此函数内部的 malloc 赋值会反映到 main 的数组 arr 中
			这里体现了 C 中“通过指针修改数组元素”的传参机制：数组名退化为指针，函数内部能修改数组元素，但不能改变数组名本身
		*/
		*(arr + i) = (int *)malloc(sizeof(int));
		**(arr + i) = i;
		printf("%d ", **(arr + i));
	}
	for (int i = 0; i < 5; i++)
	{
		free(*(arr + i));
	}
}

int	main(void)
{
	int	vector[5] = {6, 7, 8, 9, 10};

	int *arr[5]; // 数组名 arr 在表达式中会 退化成指针，类型是 int **，指向数组首元素
	displayArray(vector, 5);
	printf("\n");
	displayArray2(vector, 5);
	printf("\n");
	// 不能直接把 vector 这样的普通 int 数组传给 displayArray3，原因在于类型不匹配
	// vector的每个元素的类型是int，displayArray3 期望的元素类型是 int*
	displayArray3(arr, 5);
	printf("\n");
	return (0);
}

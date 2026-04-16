#include <stdio.h>

int	main(void)
{
	int	vector[5] = {1, 2, 3, 4, 5};
	int	*pv;
	int	i;

	pv = vector;
	printf("vector address: %p\n", vector);
	printf("&vector[0] = %p\n", &vector[0]);
	printf("pv = %p\n", pv);
	printf("\n");
	printf("element value of array =  ");
	for (i = 0; i < 5; i++)
	{
		printf("%d ", vector[i]);
	}
	printf("\n");
	/*
		用数组下标获取数组元素的值pv[i] 等价于用指针解引用获取数组元素的值*(pv+i);
		pv[i] / vector[i]的理解：位置从首元素pv或vector开始，移动i个位置，然后取出内容
		然而 *(pv+i) / *(vector+i)的理解：从pv或vector开始，在地址上增加i，然后取出这个地址中的内容
	*/
	printf("element value with index =  ");
	for (i = 0; i < 5; i++)
	{
		printf("%d ", pv[i]);
	}
	printf("\n");
	printf("element value with pointer = ");
	for (i = 0; i < 5; i++)
	{
		printf("%d ", *(pv + i));
	}
	printf("\n");
	// vector是数组名，可以理解为退化成类似指针，指向数组首元素的地址
	// 因此也可以通过类似解引用的方式 *(vector + i) 获取每个元素的值，但注意vector不是指针，只是可以达到和指针一样的效果
	// 注意：指针pv是变量，可以修改，是一个左值，数组名vector不能修改，它不是左值，只能修改vector的内容
	printf("element value with vector = ");
	for (i = 0; i < 5; i++)
	{
		printf("%d ", *(vector + i));
	}
	printf("\n");
	//指针的长度和数组的长度不是同一个东西
	printf("length of pointer = %lu \n", sizeof(pv));
	printf("length of array = %lu \n", sizeof(vector));
	return (0);
}

#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	i;
	int	arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int	*p;
	int	**pt;

	printf("使用数组下标输出元素: ");
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n\n");
	p = arr; // 指针和数组建立关系，指针指向数组首元素地址
	printf("使用一级指针输出元素: ");
	for (i = 0; i < 10; i++)
	{
		printf("%d ", *p++);
	}
	printf("\n\n");
	p = arr; // 让指针重新指向数组的首元素
	pt = &p;
	printf("使用二级指针输出元素: ");
	for (i = 0; i < 10; i++)
	{
		// printf("%d ", *(*pt)++); // 输出结果和下面这行一样, (*pt)++ 是“移动式访问”，会改变指针 p
		/*
			*pt 得到 p（地址), *(*pt + i) 是“索引式访问”，不改变指针本身,*pt 得到 p（地址）,
			*(*pt + i) → 解引用这个新地址 → 得到 arr[i]
			也就是:
			*(*pt + 0) == *p     == arr[0]
			*(*pt + 1) == *(p+1) == arr[1]
			*(*pt + 2) == *(p+2) == arr[2]
			...
		*/
		printf("%d ", *(*pt + i));
	}
	printf("\n\n");
	p = arr;
	printf("使用二级指针变量**pt方式输出元素: ");
	for (i = 0; i < 10; i++)
	{
		printf("%d ", **pt); // 指针pt没变，它始终指向 p 的地址, **pt 实时取 *p 的值，也就是当前 p 指向的元素
		p++;                 // p 指向下一个数组元素, p 在循环中移动，所以通过 pt 访问的值是动态更新的
	}
	return (0);
}

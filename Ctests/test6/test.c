#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// 返回字符串字面量地址
char	*returnString(int num)
{
	if (num >= 0)
	{
		return ("Beijing the capital of China");
	}
	else
	{
		return ("I am living at Paris now");
	}
	return (NULL);
}

// 返回动态分配内存的地址
char	*returnVari(int num)
{
	char	*charcta;
	int		i;

	charcta = (char *)malloc(num + 1);
	for (i = 0; i < num; i++)
	{
		charcta[i] = 'a';
	}
	charcta[num] = '\0';
	return (charcta);
}

int	main(void)
{
	char	*pt1;
	char	*pt2;
	char	*charctas;

	pt1 = returnString(2);
	printf("pt1 = %c\n", *pt1);
	printf("pt1 string = %s \n", pt1);
	write(1, pt1, strlen(pt1));
	write(1, "\n", 1);
	pt2 = returnString(-2);
	printf("pt2 = %c\n", *pt2);
	printf("pt2 string = %s \n", pt2);
	write(1, pt2, strlen(pt2));
	write(1, "\n", 1);
	charctas = returnVari(6);
	printf("charctas = %s\n", charctas);
	free(charctas);
	return (0);
}

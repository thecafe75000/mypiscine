
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	destlen;
	unsigned int	srclen;

	destlen = 0;
	while (dest[destlen] && destlen < size)
		destlen++;
	srclen = 0;
	while (src[srclen])
		srclen++;
	if (size <= destlen)
		return (size + srclen);
	i = 0;
	while (src[i] && (destlen + i) < (size - 1))
	{
		dest[destlen + i] = src[i];
		i++;
	}
	dest[destlen + i] = '\0';
	return (destlen + srclen);
}
/*
#include <stdio.h>
#include <string.h>
#include <bsd/string.h>
int i = 0;
void	strlcat_test(char* dest, char* dest2, char* src, unsigned int size)
{
	unsigned int destlen = 0, srclen = 0;
	while (dest[destlen] != '\0' && destlen < size)
		destlen++;
	while (src[srclen] != '\0')
		srclen++;

	printf("%d\n", i++);
	printf("dest(%d):%s\t\tsrc (%d):%s\tsize:%d\n",
		destlen, dest, srclen, src, size);
	int ft = ft_strlcat(dest, src, size);
	printf("ft_:(%d) %s\n-----\n", ft, dest);

	destlen = 0;
	while (dest2[destlen] != '\0' && destlen < size)
		destlen++;
	printf("dest2(%d):%s\t\tsrc (%d):%s\tsize:%d\n",
		destlen, dest2, srclen, src, size);
	int sys = strlcat(dest2, src, size);
	if (ft == sys)
		printf("sys(%d): %s\n=====\n\n", sys, dest2);
	else
		printf("sys(%d): %s\n=====\n!!!!!!!!!!\n\n", sys, dest2);
}

int	main(void)
{
	char a[50] = "0123456789";
	char aa[50] = "0123456789";
	char b[10] = "abc";
	char bb[10] = "abc";
	char c[20] = "$$3.141592653549$$";
	char d[1] = "";

	strlcat_test(a, aa, b, 50);
	strlcat_test(b, bb, c, 10);
	strlcat_test(b, bb, d, 10);
	strlcat_test(b, bb, c, 10);
}
*/

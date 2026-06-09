
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*result;
	int		len;
	int		i;

	len = 0;
	while (src[len])
		len++;
	result = (char *)malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (0);
	i = 0;
	while (i < len)
	{
		result[i] = src[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
/*
#include <stdio.h>
#include <string.h>
int	main()
{
	char *src0 = "0123456789";
	char *src1 = "";
	char *src2 = "1";

	char *   dest0, *   dest1, *   dest2;
	char *ft_dest0, *ft_dest1, *ft_dest2;

	dest0 = strdup(src0);
	dest1 = strdup(src1);
	dest2 = strdup(src2);

	ft_dest0 = ft_strdup(src0);
	ft_dest1 = ft_strdup(src1);
	ft_dest2 = ft_strdup(src2);

	printf("%zu,%s\n%zu,%s\n%zu,%s\n",
		strlen(dest0), dest0, strlen(dest1),
		dest1, strlen(dest2), dest2);
	printf("==========\n");
	printf("%zu,%s\n%zu,%s\n%zu,%s\n",
		strlen(ft_dest0), ft_dest0, strlen(ft_dest1),
		ft_dest1, strlen(ft_dest2), ft_dest2);

	free(   dest0);free(   dest1);free(   dest2);
	free(ft_dest0);free(ft_dest1);free(ft_dest2);
}
*/

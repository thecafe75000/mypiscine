
int	ft_sqrt(int nb)
{
	int	root;

	if (nb == 0 || nb == 1)
		return (nb);
	root = 2;
	while (root < nb)
	{
		if (root == nb)
			return (0);
		if (nb == root * root)
			return (root);
		root++;
	}
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("nb:%d, %d\n",  0, ft_sqrt( 0));
	printf("nb:%d, %d\n",  1, ft_sqrt( 1));
	printf("nb:%d, %d\n",  2, ft_sqrt( 2));
	printf("nb:%d, %d\n",  4, ft_sqrt( 4));
	printf("nb:%d, %d\n",  8, ft_sqrt( 8));
	printf("nb:%d, %d\n",  9, ft_sqrt( 9));
	printf("nb:%d, %d\n", 16, ft_sqrt(16));
	printf("nb:%d, %d\n", 24, ft_sqrt(24));
	printf("nb:%d, %d\n", 25, ft_sqrt(25));
	printf("nb:%d, %d\n", 35, ft_sqrt(35));
	printf("nb:%d, %d\n", 36, ft_sqrt(36));
	printf("nb:%d, %d\n", 9801, ft_sqrt(9801));
	printf("nb:%d, %d\n", 96059601, ft_sqrt(96059601));
}
*/

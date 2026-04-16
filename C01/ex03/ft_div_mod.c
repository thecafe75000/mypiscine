
void  ft_div_mod(int a, int b, int *div, int *mod)
{
  *div = a / b;
  *mod = a % b;
}
#include <stdio.h>
int main()
{
  int a = 10;
  int b = 6;
  printf("a=%d  b=%d \n\n", a, b);
  int div;
  int mod;

  ft_div_mod(a, b, &div, &mod);
  printf("a=%d  b=%d div=%d  mod=%d \n", a, b, div, mod);
  return (0);
}


/*
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	if (ac != 3)
		return (printf("You must put two int.\n"), 1);
	int x = atoi(av[1]);
	int y = atoi(av[2]);
	int div;
	int mod;

	ft_div_mod(x, y, &div, &mod);
	printf("Division: %d, Modulo: %d\n", div, mod);
	return 0;
}
*/
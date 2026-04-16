#include <stdio.h>

void ft_value(int i)
{
  i = 42;
  printf("value i: %d \n\n", i);
}
void ft_addr(int *p)
{
   printf("addr: %p \n\n", p);
}
void ft_pointer(int *p)
{
   printf("pointer: %p \n\n", p);
}

 void ft_pointer_addr(int **p)
 {
    printf("pointer addr: %p \n\n", p);
 }
void  ft_ft(int *p)
{
  *p = 42;
}

int main()
{
  int a = 0;
  int *p = &a;
  ft_value(a);
  printf("value: %d \n\n", a);

  ft_addr(&a);
  ft_pointer(p);
  ft_pointer_addr(&p);

  ft_ft(&a);
  printf("%d ", a);
  return (0);
}

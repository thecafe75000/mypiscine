void  ft_rev_int_tab(int *tab, int size)
{
  int temp;
  int i;
  int j;

  i = 0;
  j = size - 1;
  while (i < j)
  {
    temp = tab[i];
    tab[i] = tab[j];
    tab[j] = temp;
    i++;
    j--;
  }
}
#include <stdio.h>

int main()
{
  int tab[] = {-5, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int size = sizeof(tab) / sizeof(tab[0]);
  
  ft_rev_int_tab(tab, size);
  int i = 0;
  while (i < size)
  {
    printf("%d ", tab[i]);
    i++;
  }
  return (0);
}
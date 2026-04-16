void ft_sort_int_tab(int *tab, int size)
{
  int i;
  int j;
  int min;

  i = 0;
  while (i < size -1)
  {
    j = 0;
    while (j < size - 1 - i)
    {
      if (tab[j] > tab[j+1])
      {
        min = tab[j];
        tab[j] = tab[j+1];
        tab[j+1] = min;
      }
      j++;
    }
    i++;
  }
}
#include <stdio.h>

int main()
{
  int tab[] = {10, 2, 8, 5, -2, 3, 9, -8, 1, 4, 7, 6};
  int size = sizeof(tab) / sizeof(tab[0]);
  printf("length of tab: %d \n", size);

  ft_sort_int_tab(tab, size);
  int i = 0;
  while (i < size)
  {
    printf("%d ", tab[i]);
    i++;
  }
  return (0);
}

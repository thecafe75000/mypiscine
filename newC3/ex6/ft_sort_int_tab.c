
void ft_swap_value(int *tab, int posx, int posy)
{
  int temp;

  temp = tab[posx];
  tab[posx] = tab[posy];
  tab[posy] = temp;
}

void  ft_sort_int_tab(int *tab, int size)
{
  int loopcount;
  int startpos;
  int movepos;

  if (size == 0)
    return;
  loopcount = size;
  startpos = 0;
  while (startpos < loopcount)
  {
    movepos = startpos + 1;
    while (movepos < loopcount)
    {
      if (tab[movepos] < tab[startpos])
      {
        ft_swap_value(tab, startpos, movepos);
      }
      movepos++;
    }
    startpos++;
  }
}

#include <stdio.h>

int main()
{
  int arr[] = {0, -1, 6, 2, 4, 3, 5, 1};
  int size = sizeof(arr) / sizeof(arr[0]);
  ft_sort_int_tab(arr, size);
  for (int i = 0; i < size; i++)
  {
    printf("%d ", arr[i]);
  }
  return (0);
}

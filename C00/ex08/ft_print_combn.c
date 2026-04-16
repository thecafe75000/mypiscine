
#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
  write(1, &c, 1);
}

void  print_comb(int *arr, int n, int first)
{
  int   i;
  char  c;

  if(!first)
    ft_putchar(',');
  i = 0;
  while(i < n)
  {
    c = arr[i] + '0';
    ft_putchar(c);
    i++;
  }
}

void solve(int *arr, int n)
{
  int first;
  int i;

  first = 1;
  while(1)
  {
    print_comb(arr, n, first);
    first = 0;
    i = n - 1;
    while(i >= 0 && arr[i] == 10 - (n - i))
      i--;
    if(i < 0)
      break;
    arr[i]++;
    i++;
    while(i < n)
    {
      arr[i] = arr[i - 1] + 1;
      i++;
    }
  }
}

void ft_print_combn(int n)
{
  int i;
  int arr[10];

  if (n <= 0 || n >= 10)
    return;
  i = 0;
  while(i < n)
  {
    arr[i] = i;
    i++;
  }
  solve(arr, n);
}
int main()
{
  ft_print_combn(2);
  printf("\n\n");
  ft_print_combn(3);
  printf("\n\n");
  ft_print_combn(9);
  return (0);
}

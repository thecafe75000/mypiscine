
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: string <string>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 21:01:43 by string            #+#    #+#             */
/*   Updated: 2026/03/09 21:01:43 by string           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
void ft_rev_int_tab(int *tab, int size)
{
  int i;
  int temp;

  i = 0;
  while (i < size)
  {
    temp = tab[i];
    tab[i] = tab[size - 1];
    tab[size - 1] = temp;
    i++;
    size--;
  }
}
*/

void ft_rev_int_tab(int *tab, int size)
{
  int *leftp;
  int *rightp;
  int count;
  int temp;

  leftp = tab;
  rightp = tab + (size - 1);
  count = size / 2;
  while (count > 0)
  {
    temp = *leftp;
    *leftp = *rightp;
    *rightp = temp;
    leftp++;
    rightp--;
    count--;
  }
}


#include <stdio.h>

int main()
{
  int arr[] = {1, 2, 3, 4, 5, 6, 7};
  int size = sizeof(arr) / sizeof(arr[0]);
  ft_rev_int_tab(arr, size);
  for (int i = 0; i < size; i++)
  {
    printf("%d ", arr[i]);
  }
    return (0);
}

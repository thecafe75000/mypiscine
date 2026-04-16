#include <unistd.h>
/*
 模 10，就是取最后一位；如果本来就只有一位，那结果还是它自己
 也是就是0~9的数字取10的模运算，结果都是数字本身
*/
void ft_putfournumbers(int left, int right)
{
  char c1;
  char c2;
  char c3;
  char c4;

  c1 = '0' + left / 10 % 10;   // left 的十位上的字符
  c2 = '0' + left % 10;       // left 的个位上的字符
  c3 = '0' + right / 10 % 10;
  c4 = '0' + right % 10;
  write(1, &c1, 1);
  write(1, &c2, 1);
  write(1, " ", 1);
  write(1, &c3, 1);
  write(1, &c4, 1);
}

// 数字之间的分隔：逗号及空格
void ft_putcomma(void)
{
  write(1, ", ", 2);
}

void ft_print_comb2(void)
{
  int left;
  int right;

  left = 00;
  while (left < 99)
  {
    right = left + 1;
    while (right <=99)
    {
      ft_putfournumbers(left, right);
      if (!(left == 98))
        ft_putcomma();
      right++;
    }
    left++;
  }
}

int main()
{
  ft_print_comb2();
  return (0);
}
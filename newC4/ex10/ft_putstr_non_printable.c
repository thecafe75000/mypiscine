/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: string <string>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 16:14:54 by string            #+#    #+#             */
/*   Updated: 2026/02/19 16:23:44 by string           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
  创建一个函数用于在屏幕上显示一串字符，如果该字符串包含不可打印字符
  则该non-printable字符必须以16进制小写形式显示，并在16进制字符前加上一个反斜杠\

   - 不可打印字符： char c >=0 && char c <= 31 && char c = 127, 即 非printable（0–31, 127）
   - \n, \t 虽然“能显示效果”，但 不是 printable

   所有参与十六进制计算的字符，先转成 unsigned char, 否则，负数参与 / 16、% 16，结果不可信
   别用 signed char 的数值去做 ASCII 判断或数组索引, 因为char 是一个整数类型，可以是：
   signed char → -128 ~ 127， 也可以是 unsigned char → 0 ~ 255， 由编译器决定
   不可打印字符只存在于 ASCII 的 0–127 中；负 char 不是字符，而是错误的语义解释视角
   也就是所有要操作的字符都必须在 0~255 的范围内，才安全可靠，即全部用 unsigned char 类型
   因为char 默认 signed char 的范围是 -128 ~ 127，因此必须用unsigned char，范围才会是 0 ~ 255

   快速心算口诀（考试用）
    1- 先想十进制
    2- 除 16 得高位
    3- 取余 16 得低位
    4- 0–9 数字，10–15 a–f
    5- 负 char = 先转 unsigned

    思路：
    1- 遍历字符串：用 while (*str) 逐个字符处理
    2- 类型转换：unsigned char c = (unsigned char)*str; 避免 signed char 负值导致误判或数组越界
    3- 判断是否不可打印：c < 32 || c == 127 是不可打印 则输出 \xx, 或 可打印, 则直接输出
    4- 不可打印字符输出：拆分高低位 → /16 取高位，%16 取低位，然后查表 "0123456789abcdef" 得字符，再输出 \ + 高位字符 + 低位字符
    5- 可打印字符输出：直接 write(1, str, 1)
    6- 循环处理直到 '\0'
*/

#include <unistd.h>

void  ft_putchar(unsigned char c)
{
  write(1, &c, 1);
}

void ft_change2hex(unsigned c)
{
  char *hex;

  hex = "0123456789abcdef";
  write(1, "\\", 1);
  ft_putchar(hex[c / 16]);  // 16进制的高位
  ft_putchar(hex[c % 16]);  // 16进制的低位
}

void ft_putstr_non_printable(char *str)
{
  int i;
  unsigned char c;

  i = 0;
  while (str[i])
  {
    c = (unsigned char)str[i];
    if (str[i] == 127 || (str[i] >= 0 && str[i] <= 31))
      ft_change2hex(c);
    else
      ft_putchar(c);
    i++;
  }
}

#include <stdio.h>

int main()
{
  char arr[] = "Hello\nHow are you?";
  char arr2[] = "here is Paris* \t";
  ft_putstr_non_printable(arr);
  printf("\n");
  ft_putstr_non_printable(arr2);
  return (0);
}

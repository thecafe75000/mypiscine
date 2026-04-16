#include <stdio.h>
typedef int (*pointerfn)(int, int); // 声明一个函数指针类型

int fn1(int a, int b)
{
  return (a + b);
}
int fn2(int a, int b)
{
  return (a * b);
}

int main()
{
  int a = 10;
  int b = 90;
  // int (*pfn)(int, int); // 声明一个函数指针
  pointerfn pfn;
  pfn = fn1; // 函数指针先指向fn1
  printf("a+b with pointer: %d\n", pfn(a, b));
  printf("a+b: %d\n\n", fn1(a, b));
  pfn = fn2; // 函数指针改变指向，指向fn2
  printf("a*b with pointer: %d\n", pfn(a, b));
  printf("a*b: %d\n", fn2(a, b));
  return (0);
}
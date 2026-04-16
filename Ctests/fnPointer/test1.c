#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int myfn(int a, int b)
{
  return (a + b);
}

int myfn2(int a, int b)
{
  return (a * b);
}

char *getMemery() // 指针函数是返回值类型为指针的函数
{
  char *pc = (char *)malloc(100);
  return pc;
}

int main()
{
  int x = 10;
  int y = 60;
  int (*pmyfn)(int, int) = myfn; // pmyfn 是函数指针
  int result1 = myfn(x, y);
  int result2 = pmyfn(x, y);
  printf("result1 = %d, result2 = %d \n", result1, result2);

  pmyfn = myfn2; // 改变了函数指针pmyfn的指向
  int result3 = pmyfn(x, y);
  printf("result1 = %d, result2 = %d, result3 = %d \n", result1, result2, result3);

  char *str = getMemery();
  strcpy(str, "hello function pointer");
  printf("str = %s \n", str);
  free(str); 
  str = NULL; // 虽然释放了内存，但指针仍然指向getMemery的地址，这一步必要的，让指针str指向空才不会指向getMemery函数的地址
  printf("free str = %s \n", str);
  return (0);
}
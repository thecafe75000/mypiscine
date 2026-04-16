#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
char  *fn1()
{
  char str[10];
  strcpy(str, "hello!");
  return str;  // str是局部变量地址，出了fn1，局部变量自动释放，不能再访问
}
*/

char *fn2()
{
  static char str2[10]; // 静态变量要等整个程序结束才会被回收，因此main调用fn2没问题
  strcpy(str2, "hello!");
  return str2;
}

char *fn3()
{
  // char str3[] = "here is paris"; // str3是一个数组对象，它是在栈上的局部变量，因此main调用不了
  char *str3 = "here is paris"; // 常量要等整个程序结束才会被回收，str3是一个指针变量，指向字符串常量即字面量，因此main调用fn3没问题
  return str3;
}

char *fn4()
{
  char *str4 = NULL;
  str4 = (char *)malloc(8); // str4是在堆上的地址，又程序员自己来释放，因此main调用fn4没问题
  if (str4 == NULL)
  {
    printf("malloc error \n");
    return str4;
  }
  strcpy(str4, "welcome");
  return str4;
}

int main()
{
  // printf("%s\n", fn1());
  printf("fn2: %s\n\n", fn2());
  printf("fn3: %s\n\n", fn3());

  char *pstr4 = fn4();
  printf("fn4: %s\n\n", pstr4);
  free(pstr4);
  return (0);
}
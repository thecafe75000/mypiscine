#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_print_combn(int n)
{
    int arr[10];
    int i;
    int first; // 用于标记当前的数字组合是不是第一个
    int done; // 是否已经枚举完所有合法数字组合，用于显式控制循环终止

    if (n <= 0 || n >= 10)
        return;

    /* ① 初始化第一个组合：0,1,2,...,n-1 */
    i = 0;
    while (i < n)
    {
        arr[i] = i;
        i++;
    }

    first = 1;
    done = 0;

    /* ② 条件明确的主循环 */
    while (!done)
    {
        /* —— 打印当前组合 —— */
        if (!first)
            write(1, ", ", 2);
        first = 0;

        i = 0;
        while (i < n)
        {
            ft_putchar(arr[i] + '0');
            i++;
        }

        /* —— 查找是否还能生成下一个组合 —— */
        i = n - 1;
        while (i >= 0 && arr[i] == 10 - (n - i)) // 对于第 i 位，最大值 = 10 - (n - i)
            i--;

        /* 如果没有可增长位，标记结束 */
        if (i < 0)
        {
            done = 1;
        }
        else
        {
            /* —— 生成下一个组合 —— */
            arr[i]++;
            i++; // 先跳到右边位
            while (i < n)
            {
                arr[i] = arr[i - 1] + 1; // 每一位 = 左边位 + 1
                i++; // 重置后续位, 循环直到 i = n → 完成整个右边段的重置
            }
        }
    }
}

#include <stdio.h>

int main()
{
  ft_print_combn(2);
  printf("\n\n");
  ft_print_combn(3);
  printf("\n\n");
  ft_print_combn(9);
  return (0);
}

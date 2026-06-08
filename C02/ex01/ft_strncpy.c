
#include <stdlib.h>
#include <string.h>
/*
  dest -- 指向用于存储复制内容的目标数组
  src -- 要复制的字符串
  n -- 要从src中复制的最多字符数, 当src的长度 < n时，dest 的剩余部分用空字节填充
  返回最终复制的字符串

  不用写if (dest == NULL || src == NULL)，不需要对传入的参数进行判断
  因为标准库函数（包括 strncpy）的设计理念是“调用者负责保证参数合法。”
  标准库默认：“你既然调用我，就应该传合法地址。” C语言里“库函数不帮你纠错”，是很核心的哲学
  而不是“函数内部帮你防御所有错误参数。”
*/
char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

#include <stdio.h>

// int main(int ac, char **av)
// {
//   (void)ac;
//   char *str = av[1];
//   unsigned int n = atoi(av[2]);
//   char dest1[30], dest2[30];
//   strncpy(dest1, str, n);
//   ft_strncpy(dest2, str, n);
//   printf("%s\n%s", dest1, dest2);
// }

int	main(void)
{
	char	src[] = "abcd123*";
	char	dest[12];

	// strncpy(dest, src, 3);
	// int i = 0;
	// while (i < 9)
	// {
	//   printf("%c", dest[i]);
	//   i++;
	// }
	// printf("%s", dest);
	ft_strncpy(dest, src, 5);
	printf("%s", dest);
	return (0);
}

/*
Assignment name  : alpha_mirror
Expected files   : alpha_mirror.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a program called alpha_mirror that takes a string and displays this string
after replacing each alphabetical character by the opposite alphabetical
character, followed by a newline.
'a' becomes 'z', 'Z' becomes 'A'
'd' becomes 'w', 'M' becomes 'N'
and so on.
Case is not changed.
If the number of arguments is not 1, display only a newline.

Examples:
$>./alpha_mirror "abc"
zyx
$>./alpha_mirror "My horse is Amazing." | cat -e
Nb slihv rh Znzarmt.$
$>./alpha_mirror | cat -e
$
$>

	这题要求：
		如果参数正好是 1 个：
			遍历字符串
			小写字母换成对应反向小写字母
			大写字母换成对应反向大写字母
			其他字符不变，直接输出
			就是把字母表反过来对应如下：
				a b c d e ... w x y z
				z y x w v ... d c b a
		最后输出换行

	核心代码：
		- 如果字符是小写字母：c = 'z' - (c - 'a');
			例如 c = 'd'，c - 'a' 是 3，所以结果是 'z' - 3，也就是 'w'
		- 如果字符是大写字母：c = 'Z' - (c - 'A');
			例如 M 离 A 是 12 位，所以结果是 Z - 12，也就是 N

*/

#include <unistd.h>

int	main(int argc, char **argv)
{
	int		i;
	char	c;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (argv[1][i])
	{
		c = argv[1][i];
		if (c >= 'a' && c <= 'z')
			c = 'z' - (c - 'a');
		else if (c >= 'A' && c <= 'Z')
			c = 'Z' - (c - 'A');
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}

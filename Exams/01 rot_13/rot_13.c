/*
Assignment name  : rot_13
Expected files   : rot_13.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a program that takes a string and displays it, replacing each of its
letters by the letter 13 spaces ahead in alphabetical order.

'z' becomes 'm' and 'Z' becomes 'M'. Case remains unaffected.

The output will be followed by a newline.

If the number of arguments is not 1, the program displays a newline.

Example:
$>./rot_13 "abc"
nop
$>./rot_13 "My horse is Amazing." | cat -e
Zl ubefr vf Nznmvat.$
$>./rot_13 "AkjhZ zLKIJz , 23y " | cat -e
NxwuM mYXVWm , 23l $
$>./rot_13 | cat -e
$
$>
$>./rot_13 "" | cat -e
$
$>
	字母往后移动 13 位
	大小写不变：
		a 变成 n，不会变成 N
		A 变成 N，不会变成 n
	非字母不变：
		空格、逗号、句号、数字都原样输出

	因为 ROT13 是“字母向后移动 13 位”，而英文字母一共有 26 个，正好分成两半：
		a b c d e f g h i j k l m
		n o p q r s t u v w x y z
	对前半段来说，直接 +13 不会超过 z：
		a + 13 = n
		b + 13 = o
		...
		m + 13 = z
	但是对后半段来说，如果继续 +13，就会超出字母范围, ROT13 要求超过 z 后从 a 重新开始,
	这个效果可以用减13实现：
		n - 13 = a
		o - 13 = b
		...
		z - 13 = m
	大写字母同理：
		A 到 M  +13
		N 到 Z  -13
*/

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (argv[1][i])
	{
		if ((argv[1][i] >= 'a' && argv[1][i] <= 'm') || (argv[1][i] >= 'A'
				&& argv[1][i] <= 'M'))
			argv[1][i] += 13;
		else if ((argv[1][i] >= 'n' && argv[1][i] <= 'z') || (argv[1][i] >= 'N'
				&& argv[1][i] <= 'Z'))
			argv[1][i] -= 13;
		write(1, &argv[1][i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}


/*
Assignment name  : hidenp
Expected files   : hidenp.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a program named hidenp that takes two strings and displays 1
followed by a newline if the first string is hidden in the second one,
otherwise displays 0 followed by a newline.
Let s1 and s2 be strings. We say that s1 is hidden in s2 if it's possible to
find each character from s1 in s2, in the same order as they appear in s1.
Also, the empty string is hidden in any string.
If the number of parameters is not 2, the program displays a newline.

Examples :
$>./hidenp "fgex.;" "tyf34gdgf;'ektufjhgdgex.;.;rtjynur6" | cat -e
1$
$>./hidenp "abc" "2altrb53c.sse" | cat -e
1$
$>./hidenp "abc" "btarc" | cat -e
0$
$>./hidenp | cat -e
$
$>

	程序接收 两个字符串参数s1和s2:
	如果 s1 可以按顺序“藏在” s2 里面，就输出 1, 否则输出 0
	s1 的每个字符，都能在 s2 中按相同顺序找到，但不要求连续
	空字符串 "" 永远算是隐藏在任何字符串里，所以应该输出 1
	最后都要换行

	核心判断逻辑就是：
		从左到右扫描 s2
		如果当前 s2 字符等于 s1 当前需要匹配的字符，就移动到 s1 的下一个字符
		最后如果 s1 全部匹配完，输出 1，否则输出 0
		也就是：在 s2 中，从左到右，依次寻找 s1 的字符,找到一个，就继续寻找下一个, 直到全部找到或搜索结束
		
	这题就是检查argv[1] 是否是 argv[2] 的子序列
	情况1：argv[1] 先结束，argv[1] 全部匹配完成，说明argv[1] 是 argv[2] 的子序列
	情况2：argv[2] 已经没有字符可用了，但 argv[1] 还没匹配完，则说明说明argv[1] 不是 argv[2] 的子序列
*/

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	j = 0;
	// 在 argv[2] 中，从左到右，依次寻找 argv[1] 的字符。找到一个，就继续寻找下一个。直到全部找到或搜索结束
	// argv[2] 负责遍历所有字符，argv[1] 只有在匹配成功时才前进，因此 argv[1] 的“走完”是由 argv[2] 驱动完成的
	while (argv[1][i] && argv[2][j])
	{
		if (argv[1][i] == argv[2][j]) // 如果字符匹配，i 才前进，i 是被 j “触发推进”的
			i++;
		j++; // 每轮循环都增加
	}
	if (argv[1][i] == '\0')
		write(1, "1", 1);
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}

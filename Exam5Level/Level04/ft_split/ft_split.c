/*
Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------
Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.
A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:
char		**ft_split(char *str);
*/
/*
	接收一个字符串 str，把字符串按“空白字符”切成一个个单词，然后返回一个字符串数组
	这里的空白字符包括：
		' '   // 空格
		'\t'  // tab
		'\n'  // 换行
	返回值必须是一个以 NULL 结尾的 char ** 数组，
	也就是最后一个元素必须是 NULL，方便调用者知道数组在哪里结束

	要求和限制：
		只能使用 malloc
		不能用 strdup、strlen、calloc 等库函数
		你需要自己统计单词数量
		你需要给 char ** 数组分配内存
		你还需要给每个单词单独分配内存
		每个单词字符串都要以 '\0' 结尾
		返回的数组最后必须放 NULL
	简单说：这题就是让你手写一个按空格、tab、换行分割字符串的函数
	例如：
	ft_split("  hello\tworld\n42  ")
	应该返回：[
				"hello",
				"world",
				"42",
				NULL
			]
	注意返回的是字符串数组(char **)，而不是单个的字符串，
		也就是返回的数组的每个元素是一个字符串

	按“从 0 开始写出完整程序”的方式解释这题怎么想、怎么拆、为什么这样构思
*/

#include <stdlib.h>

static int	is_space(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

/*
	i 表示当前位置，即现在正在检查字符串的第几个字符
		作用是沿着字符串从左往右走，记录当前扫描到哪里了
	count 是“已经发现了多少个单词”，它不是字符串下标，也不是字符数量
		作用是记录目前找到的单词数量, 用来给malloc申请内存空间大小

	外层 while 进来一次
		第一个内层 while 跑完
		if 判断一次
		第二个内层 while 跑完
	外层 while 再决定要不要进下一次
*/
static int	count_words(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && is_space(str[i])) // 这个 while 负责“跳过一段空白”
			i++;
		if (str[i]) // 如果没到原始字符串结尾，说明遇到一个单词，要count++
			count++;
		while (str[i] && !is_space(str[i]))
			// 这个 while 负责“跳过一个完整单词”，即从单词开头一直走到单词结尾
			i++;
	}
	return (count);
}

static char	*copy_word(char *str, int start, int len)
{
	char	*word;
	int		i;

	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str)
{
	char	**result;
	int		k;
	int		j;
	int		start;
	int		words;

	words = count_words(str);
	result = (char **)malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	k = 0;
	j = 0;
	// 下面的while循环是为了填充result数组
	// k = 扫描原字符串 str 的位置, 会在每个字符之间移动很多次
	// j = 填充 result 数组的位置, 只在成功放入一个单词后移动一次
	while (str[k])
	{
		while (str[k] && is_space(str[k]))
			k++;
		start = k;
		while (str[k] && !is_space(str[k]))
			k++;
		if (k > start)
		{
			// result[j] 负责保存每个复制出来的单词(1个单词就是一个字符串)
			result[j] = copy_word(str, start, k - start);
			j++;
		}
	}
	result[j] = NULL;
	return (result);
}

#include <stdio.h>

int	main(void)
{
	char	*str;
	char	**result;
	int		i;

	str = "  hi here is paris city !";
	result = ft_split(str);
	i = 0;
	while (result[i])
	{
		printf("result[%d] = %s\n", i, result[i]);
		i++;
	}
	printf("result[%d] = NULL\n", i);
	return (0);
}

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
char	**ft_split(char *str);

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

	算法：
	这题要拆成3个独立步骤
	Step A: 统计单词数量(决定malloc多大)
		必须先扫一遍字符串
		规则：一个word = 连续非空白字符序列
		空白字符包括：’ ‘, '\t', '\n'
		扫描过程：
		skip spaces
		hello → count = 1
		skip \t
		world → count = 2
		skip \n
		42 → count = 3
		最终：word_count = 3
	Step B: 分配结果数组（char **）
		现在知道 word 数量了：char **result = malloc(sizeof(char *) * (word_count + 1));
		为什么 +1？
		因为最后必须 result[word_count] = NULL; 这是 C 里“数组结束标志”
	Step C: 逐个提取单词（核心逻辑）
		必须要再次扫描字符串，但这次要对每个 word 做：
			1) 找起点: 跳过空白字符 → 找到第一个非空白字符
			2) 计算 word 长度, 从word起点开始一直走到空格, \t, \n 或字符串结束, 得到一个单词的length
			3）为这个 word 分配空间 result[i] = malloc(length + 1); +1 是为了 '\0'
			4）复制字符串，要逐个字符复制：result[i][j] = str[start + j];
			5）进入下一个单词 i++
	Step D: 最后的收尾
		result[word_count] = NULL;
		return (result);
	关键难点：
		错误1：没有跳过连续空格，如果不跳，会误判多个空白为多个 word
		错误2：word_count 不准确，如果统计错 → malloc 小了 → 崩溃
		错误3：忘记 NULL 结束，result[word_count] = NULL; 是必须的，否则后续遍历会爆炸
		错误4：内存泄漏（重点），如果malloc result[i] 失败，必须释放之前所有已分配的 result[i]

	理解is_in_word：
		它不是当前字符属于不属于单词，而是程序当前的“状态”，意思是
			“在处理当前字符之前，程序的状态是不是已经在一个单词里面了？”
		也就是：
			它描述的是程序之前的状态，
			即在读取当前字符之前，程序是否已经处于单词区域
*/

#include <stdlib.h>

// 判断是否是分隔字符
int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

// 统计字符串里有几个单词，也就是有几个子串
// 知道了子串的数量，可用来动态申请内存，存放指针数组，每个指针指向一个子串
int	count_words(char *str)
{
	int	i;
	int	count;
	int	is_in_word;

	i = 0;
	count = 0;
	is_in_word = 0; // 程序不处于读取一个单词的状态
	while (str[i])
	{
		if (is_in_word && is_space(str[i])) // 程序处于读取单词状态，且当前字符是一个空白字符，说明一个单词结束了
		{
			count++;
			is_in_word = 0;
		}
		else if (!is_in_word && !is_space(str[i]))
			// 程序不处于读取单词状态，且当前字符不是一个空白字符，说明一个新单词开始了
			is_in_word = 1;
		i++;
	}
	if (is_in_word) // 处理字符串结尾, 最后一个单词扫描完要计数
		count++;
	return (count);
}

// 获取单个单词(即某个子串)的长度, 给每个子串动态申请内存
// 第2个参数i是单词的起始位置，因为字符串里的单词是从任意位置开始
int	get_word_len(char *str, int i)
{
	int	len;

	len = 0;
	while (str[i] && !is_space(str[i]))
	{
		i++;
		len++;
	}
	return (len);
}

char	**ft_split(char *str)
{
	int		i;
	char	**result;
	int		words_num;
	int		j;
	int		k;
	int		start;
	int		word_len;

	i = 0;
	words_num = count_words(str);
	result = malloc(sizeof(char *) * (words_num + 1));
	if (!result)
		return (NULL);
	j = 0;
	//  开始扫描整个字符串
	while (str[i])
	{
		while (str[i] && is_space(str[i])) // 跳过分隔字符
			i++;
		if (str[i]) // 说明字符串还没走到末尾，位于单词开头，可以开始扫描单词
		{
			start = i;
			word_len = get_word_len(str, start);
			result[j] = malloc(sizeof(char) * (word_len + 1));
			if (!result[j])
				return (NULL);
			k = 0;
			// 复制单词，即逐个复制单词的每个字符
			while (k < word_len)
			{
				result[j][k] = str[start + k];
				k++;
			}
			result[j][k] = '\0';
			j++;
			// 跳过当前已经扫描过的单词
			i += word_len;
		}
	}
	result[j] = NULL;
	return (result);
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	char **strs;
	int i;

	if (argc != 2)
	{
		printf("error in parameters\n");
		return (1);
	}
	strs = ft_split(argv[1]);
	i = 0;
	while (strs != NULL && strs[i] != NULL)
	{
		printf("%d:%s\n", i, strs[i]);
		i++;
	}
	free(strs);
	return (0);
}

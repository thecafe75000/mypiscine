/*
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

*/
#include <stdlib.h>

static int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

// 统计字符串里有几个单词, 即有几个子串
static int	count_words(char *str)
{
	int	count;
	int	i;
	int	is_in_word;

	count = 0;
	i = 0;
	is_in_word = 0;
	while (str[i])
	{
		// 当前扫描状态在单词内部，但当前字符是分隔符,说明扫描了一个完整的单词
		// 扫描一个单词结束时，单词的数量就可以计数
		if (is_in_word && is_space(str[i]))
		{
			count++;
			is_in_word = 0;
		}
		else if (!is_in_word && !is_space(str[i])) // 开始一个新单词
			is_in_word = 1;
		i++;
	}
	if (is_in_word) // 处理字符串结尾, 最后一个单词扫描完要计数
		count++;
	return (count);
}

// 获取单个单词的长度
// 第2个参数i是单词的起始位置，因为字符串里的单词是从任意位置开始
static int	get_word_len(char *str, int i)
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
	char	**result;
	int		wordsnum;
	int		word_len;
	int		i;
	int		j;
	int		k;
	int		start;

	if (!str)
		return (NULL);
	wordsnum = count_words(str);
	result = malloc(sizeof(char *) * (wordsnum + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	// 开始扫描整个字符串
	while (str[i])
	{
		// 跳过分隔符
		while (str[i] && is_space(str[i]))
			i++;
		if (str[i]) // 说明字符串还没走到'\0', 开始扫描单词
		{
			start = i;
			word_len = get_word_len(str, i);
			result[j] = malloc(sizeof(char) * (word_len + 1));
			if (!result[j])
				return (NULL);
			k = 0;
			// 复制单词，即逐个复制单词的每一个字符
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
	char	**strs;
	int		i;

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

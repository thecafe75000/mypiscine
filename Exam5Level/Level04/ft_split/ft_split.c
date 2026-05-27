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
	// k = 扫描原字符串 str 的位置, 从头开始移动扫描所有字符一直到字符串末尾
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

/*
	题目要求：把一个字符串切成多个单词，返回 char **数组
		比如："  hi here is paris city !"
	最终要得到：
		result[0] = "hi"
		result[1] = "here"
		result[2] = "is"
		result[3] = "paris"
		result[4] = "city"
		result[5] = "!"
		result[6] = NULL

	这题的算法：
		第1步：先明确什么是单词，题目说，单词由空格、tab、换行分隔
			那么不是分隔符的连续一段字符，就是单词，比如“  hi here" 可以看成
			[空白][单词][空白][单词]
			__    hi    _    here
		因此算法操作就是：
			跳过空白
			找到单词
			跳过单词
			再跳过空白
			再找到单词

		第2步：先数整个字符串里一共有几个被空白字符隔开的单词总数
			因为最后要返回的是 char **result, 这是一个数组
			必须先知道这个数组需要多大，如果有6个单词就要分配7个位置
		所以第1轮扫描字符串的目的就是数单词个数，数单词的逻辑是：
			从字符串开头开始
			只要没到结尾：
				先跳过所有空白字符
				如果跳完空白后还没到结尾：
					说明现在站在一个单词开头
					单词数量 + 1
				继续跳过这个完整单词
		例如："  hi here is paris city !", 过程就是：
			跳过开头两个空格
			遇到 hi，count = 1
			跳过 hi

			跳过一个空格
			遇到 here，count = 2
			跳过 here

			跳过一个空格
			遇到 is，count = 3
			跳过 is

			跳过一个空格
			遇到 paris，count = 4
			跳过 paris

			跳过一个空格
			遇到 city，count = 5
			跳过 city

			跳过一个空格
			遇到 !，count = 6
			跳过 !

			到结尾
			得到words = 6

		第3步：分配result数组，现在知道有6个单词，所以分配
			result = malloc(sizeof(char *) * (words + 1));
			这里的 result 不是存字符的，它存的是 char * 指针
			每个 result[j] 将来都会指向一个单词字符串，结构是：
				result[0] -> 第 1 个单词
				result[1] -> 第 2 个单词
				result[2] -> 第 3 个单词
				...
				result[6] -> NULL

		第4步：重新从头扫描字符串
		经过第3步，至此对原字符串的第1轮扫描已经把下标index走到字符串结尾了，知道了原字符串里有几个单词
		那么现在要把每个单词复制出来，所以必须重新从字符串开头再次扫描：
			k = 0; -> k = 原字符串 str 的扫描位置，即下标index
			j = 0; -> j = result 数组当前要填的位置
		为了复制单词，对字符串进行第2次从头到尾进行扫描，找到一个单词的开始位置，
		还是要先跳过空白：
			while (str[i] 是空白)
				i++;
		比如："  hi here is paris city !", 一开始跳过2个空格后，下标来到字符h，
			h是单词的开头, 所以记录start = k, 对于第1个单词hi，start = 2，
			因为前面2个空格占据了下标0,1，下标走到 h 的时候 k = 2

		第5步：找到这个单词的结束位置
		从 start 开始往后走，只要不是空白，就继续走：
			while (str[i] 不是空白)
				i++;
		对于第1个单词 “hi”, 下标k从2走到4，这时：
			start = 2
			k = 4
		注意：k 不是停留在单词hi的第2个字符‘i'这里，而是停在 hi 后面的空格处
		所以单词范围是：
				str[start] 到 str[k - 1]，也就是str[2] 到 str[3]
			单词长度是：
				i - start, 也就是 4 - 2 = 2

		第6步：复制这个单词
		现在知道start = 2, len = 2, 说明要从原字符串 str[2] 开始，复制2个字符
		因为要返回独立的新字符串，所以要malloc：
			word = malloc(sizeof(char) * (len + 1));
		len + 1 是因为字符串末尾要放上'\0'， 然后进行单词的复制：
			word[0] = str[start + 0]
			word[1] = str[start + 1]
			word[2] = '\0'
		于是得到一个新字符串 “hi", 也就是复制了原字符串里的第1个单词

		第7步：把复制出来的单词放进 result
		复制出来的 word 是一个 char *，现在要把它保存到result数组里：
			result[j] = word;
		第1次：j = 0, 因此result[0] = "hi";
		然后： j++, 变成j = 1; 意思是下一个单词要放进 result[1]

		第8步：重复处理"hi"后面的单词
		现在 k 停在 "hi" 后面的空格, 继续外层循环：
			跳过空白
			记录 start
			跳过单词
			算长度
			复制单词
			放进 result[j]
			j++
		每处理一个单词，k 往后扫描原字符串，j往后移动 result 的位置

		第9步：给 result 数组结尾放 NULL
		所有单词都放完后，j = 6, 必须写 result[j] = NULL;
		也就是 result[6] = NULL; 为什么需要做这步？
		因为 char ** 数组本身不知道长度，调用者以后会这样遍历：
			i = 0;
			while (result[i])
			{
				printf("%s\n", result[i]);
				i++;
			}
		如果没有最后的 NULL，这个循环不知道什么时候停

		最终算法整体流程：
			1. 定义哪些字符是分隔符：空格、tab、换行
			2. 第一次扫描字符串，统计单词数量 words
			3. 根据 words 分配 result 数组
				大小是 words + 1，因为最后要放 NULL
			4. 从字符串开头重新扫描
			5. 跳过连续分隔符
			6. 记录当前单词开头 start, 往后走到单词结尾，得到长度 len = i - start
			7. malloc 一个新字符串 word，复制这个单词
			8. 把 word 放进 result[j]，然后 j++
			9. 所有单词处理完后，result[j] = NULL，返回 result
		一句话概括这个算法：
			先数单词，分配外层数组；
			再逐个定位单词，分配内层字符串；
			最后把每个字符串地址放进数组，并用 NULL 结束
*/

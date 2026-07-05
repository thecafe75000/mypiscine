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

接收一个字符串 str，把字符串按“空白字符”切成一个个单词，然后返回一个字符串数组
	这里的空白字符包括：
		' '   // 空格
		'\t'  // tab
		'\n'  // 换行
	返回值必须是一个以 NULL 结尾的 char ** 数组，
	也就是最后一个元素必须是 NULL，方便调用者知道数组在哪里结束
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

	结构是：
	result
		|
		v
	+-----------+
	| result[0] | ---> 'h' 'i' '\0'   result[0] = "hi"
	+-----------+
	| result[1] | ---> 'h' 'e' 'r' 'e' '\0'   result[1] = "here";
	+-----------+
	| result[2] | ---> NULL  result[2] = NULL;
	+-----------+
	result        // char **，字符串数组的起始地址
	result[0]     // char *，第一个字符串 "hi"
	result[0][0]  // char，第一个字符串的第一个字符 'h'
	result[0][1]  // char，第一个字符串的第二个字符 'i'
	result[1]     // char *，第二个字符串 "here"
	result[1][2]  // char，第二个字符串的第三个字符 'r'

	总结:
		char **result  = 字符串数组, 数组每个元素都是一个字符串
		result[j]      = 一个字符串(字符数组)，数组每个元素都是一个字符
		result[j][k]   = 一个字符

*/

#include <stdlib.h>

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

// 统计字符串里有几个单词，即有几个子串，用于malloc申请内存
int	get_words_num(char *str)
{
	int	count;
	int	i;
	int	is_in_word;

	count = 0;
	i = 0;
	// 标记当前字符“是否在单词里”, `0` = 不在单词里（空格区）,`1` = 在单词里（单词内部）
	is_in_word = 0;
	while (str[i])
	{
		/*
			单词数量 = 字符串中从 OUT（空白区）进入 IN（单词区）的次数
			进入单词区域几次，就有几个单词
			如果当前不在单词里面 并且 当前字符不是空格，我刚刚从空格区域进入了一个单词
			这就是发现了一个新单词
			注意：! 叫逻辑非（logical NOT）, 它不会改变变量代表的意义,它只是把真假反过来
			!is_in_word 这里得到的 1 不是说在单词里面，而是指”表达式本身是真的“
			即!is_in_word这个表达式是真,不改变 is_in_word = 0 这个值
			也就是!is_in_word 其实就是 is_in_word == 0，两者完全等价
			都表示如果当前字符不在单词里面
			认为!is_in_word 的值是 1，所以应该是当前在单词里面，
			是把表达式的结果和变量表示的状态混在一起了
		*/
		if (!is_in_word && !is_space(str[i]))
		{
			count++;
			is_in_word = 1;
		}
		else if (is_space(str[i])) // 如果当前是空格，说明单词结束了
			is_in_word = 0;        // 标记“我已经离开单词区域了”
		i++;
	}
	return (count); // 返回“总共进入单词区域的次数”, 也就是单词数量
} // 一定要记住:count++ 只发生在这一瞬间：空格 → 非空格, 不是数字符，也不是数空格，而是数“进入状态的次数”
// 获取单个单词的长度, 用于malloc申请内存
// 第2个参数i是单词的起始位置(由外部传进来的起始位置)，因为字符串里的单词是从任意位置开始
int	get_word_length(char *str, int i)
{
	int len;

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
	int		word_num;
	int		word_len;
	char	**result;
	int		i;
	int		j;
	int		start;
	int		k;

	if (!str)
		return (NULL);
	word_num = get_words_num(str);
	// 创建外层数组：存放 char * 指针的数组
	result = malloc(sizeof(char *) * (word_num + 1));
	if (!result) // 如果 malloc 没有分配成功（返回 NULL），就直接返回 NULL，终止函数
		return (NULL);
	i = 0;
	j = 0;
	// 开始扫描整个字符串
	while (str[i]) // 这个str[i]的作用是先保证没到字符串结尾，再做后续判断
	{
		while (str[i] && is_space(str[i]))
			// 这个str[i]的作用是只有当前字符存在时，才去判断它是不是空白字符
			i++;
		if (str[i]) // 说明字符串还没走到'\0', 开始扫描单词
		{
			start = i;
			word_len = get_word_length(str, i);
			// 创建内层数组：存放每个 char * 指向的真正单词内容
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
			j++;           // j 表示当前正在存放第几个单词，只有找到一个完整单词后，才需要前进一次
			i += word_len; // 跳过当前已经扫描过的单词
		}
	}
	result[j] = NULL; // 必须放在整个扫描结束之后，而不能放在 if 里面, 因为不是每处理一个单词就加结束标志，而是给数组加结束标志
	return (result);
}

#include <stdio.h>

int	main(void)
{
	char	**result;
	int		i;

	result = ft_split("123456 hello 99  great42");
	i = 0;
	while (result[i])
	{
		printf("result[%d] = %s\n", i, result[i]);
		i++;
	}
	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (0);
}

int	main00(int argc, char **argv)
{
	char	**strs;
	int		i;

	if (argc != 2)
	{
		printf("error in parameters\n");
		return (1);
	}
	strs = ft_split(argv[1]);
	if (!strs)
		return (1);
	i = 0;
	while (strs[i])
	{
		printf("%d:%s\n", i, strs[i]);
		i++;
	}
	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (0);
}

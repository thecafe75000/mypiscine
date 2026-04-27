#include "rush01.h"

// 检查用户输入是否合法，并把输入里的 16 个提示数字存进 inputs 数组
int	check_user_inputs(char *str, int inputs[16])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (j >= 16 || str[i] < '1' || str[i] > '4')
			return (0);
		inputs[j] = str[i] - '0';
		j++;
		i++;
		if (j < 16)
		{
			if (str[i] != ' ')
				return (0);
			i++;
		}
		else if (str[i] != '\0')
			return (0);
	}
	return (j == 16);
}

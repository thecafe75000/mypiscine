#include "rush01.h"

int	parse_input(char *str, int clues[16])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (j >= 16 || str[i] < '1' || str[i] > '4')
			return (0);
		clues[j] = str[i] - '0';
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

#include <unistd.h>

int	is_pal(char *str, int start, int end)
{
	while (start < end)
	{
		if (str[start] != str[end])
			return (0);
		start++;
		end--;
	}
	return (1);
}

void	print_pal(char *str)
{
	int	i;
	int	j;
	int	best[2];

	best[0] = 0;
	best[1] = 0;
	i = 0;
	while (str[i])
	{
		j = i;
		while (str[j])
		{
			if (is_pal(str, i, j) && j - i >= best[1] - best[0])
			{
				best[0] = i;
				best[1] = j;
			}
			j++;
		}
		i++;
	}
	write(1, str + best[0], best[1] - best[0] + 1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		print_pal(argv[1]);
	write(1, "\n", 1);
	return (0);
}

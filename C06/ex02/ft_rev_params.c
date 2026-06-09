
#include <unistd.h>

int	main(int argc, char **argv)
{
	char	*arg;
	int		i;

	i = argc - 1;
	while (0 < i)
	{
		arg = argv[i];
		while (*arg)
		{
			write(1, arg, 1);
			arg++;
		}
		write(1, "\n", 1);
		i--;
	}
}

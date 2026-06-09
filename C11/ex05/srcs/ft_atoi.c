
#include <unistd.h>

char	*ft_rm_space(char *str)
{
	while (*str)
	{
		if (*str == ' ' || *str == '\f' || *str == '\n' || *str == '\r'
			|| *str == '\t' || *str == '\v')
			str++;
		else
			return (str);
	}
	return (str);
}

char	*ft_calc_negative(char *str, int *negative)
{
	*negative = 1;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			*negative *= -1;
		str++;
	}
	return (str);
}

int	ft_atoi(char *str)
{
	int		result;
	int		negative;

	result = 0;
	str = ft_rm_space(str);
	str = ft_calc_negative(str, &negative);
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			result = (result * 10) + (*str - '0');
			str++;
		}
		else
			break ;
	}
	return (negative * result);
}

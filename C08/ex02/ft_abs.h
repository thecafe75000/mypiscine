
#ifndef FT_ABS_H
# define FT_ABS_H

# define ABS ft_abs

int	ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

#endif
/*
int main()
{
	int i = ABS(-112546);
}
*/

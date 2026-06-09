
#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *src)
{
	char	*result;
	int		len;
	int		i;

	len = ft_strlen(src);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (0);
	i = 0;
	while (src[i])
	{
		result[i] = src[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	struct s_stock_str	*result;

	if (ac < 0)
		return (NULL);
	result = (struct s_stock_str *)malloc((ac + 1)
			* sizeof(struct s_stock_str));
	i = 0;
	while (i < ac)
	{
		result[i].size = ft_strlen(av[i]);
		result[i].str = av[i];
		result[i].copy = ft_strdup(av[i]);
		i++;
	}
	result[i].size = 0;
	result[i].str = NULL;
	result[i].copy = NULL;
	return (result);
}
/*
#ifndef FT_STOCK_STR_H
# define FT_STOCK_STR_H

typedef struct s_stock_str
{
	int				size;
	char			*str;
	char			*copy;
}					t_stock_str;

struct s_stock_str	*ft_strs_to_tab(int ac, char **av);
void				ft_show_tab(struct s_stock_str *par);

#endif
*/

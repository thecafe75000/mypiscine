
int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
/*
#include <stdio.h>
#include <string.h>

void	strlen_test(char *str)
{
	unsigned int ft = ft_strlen(str);
	size_t sys = strlen(str);

	printf("%s\nft_:%d, sys:%zu\n%s\n", str, ft, sys, (ft!=sys?"!!!":""));
}

int	main(void)
{
	strlen_test("");
	strlen_test("abcd");
	strlen_test("abcd135");
	strlen_test("adlfna  eo\tignaEGEAeoiAqn2918  ");
	strlen_test("adlfnaeo\tignaEGEAeoiAqn2\n918dasfa"
		"oiegnaoewign938hq982th32hgqi23tnblqbt");
}
*/

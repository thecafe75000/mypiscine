#include "rush01.h"

/*
	检查用户输入的字符串是否合法，如果合法，把里面的16个字符数字存进 inputs 数组
	char *str：是从命令行里输入的字符串(数字)
	返回值:
		返回1表示输入合法:
			输入的是 1~4 的数字
		返回0表示输入非法, 比如:
			数字少了或数字多了
			有非法字符
			有 0、5、a、逗号等
			空格格式错误

	Vérifier si le string saisie est valide. Si elle est valide, stocker les 16 chiffres dans le tableau inputs.
	char *str : le string (chiffres) saisie depuis la ligne de commande.
	Valeur de retour :
		1 : L'entrée est valide : Les chiffres contient uniquement des chiffres entre 1 et 4.
		0 : L'entrée est invalide, par exemple :
			- Nombre de chiffres insuffisant ou excessif.
			- les caractères non autorisés (comme 0, 5, a, des virgules, etc.).
			- Format incorrect des espaces.

*/
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

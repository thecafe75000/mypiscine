#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	char	*error;
	char	*errorMessage;
	char	*buffer;

	error = "ERROR: ";
	errorMessage = "Not enough memory";
	buffer = (char *)malloc(strlen(error) + strlen(errorMessage));
	strcpy(buffer, error);
	strcat(buffer, errorMessage);
	printf("error = %s \n", error);
	printf("errorMessage = %s \n", errorMessage);
	printf("buffer = %s \n", buffer);

	char info[50] = "INFO: ";
	char *infoMessage = "Operation not good";
	strcat(info, infoMessage);
	printf("info = %s\n", info);
	printf("infoMessage = %s\n", infoMessage);
	return (0);
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern char **environ;
char * _getenv(char *name)
{
int i , j;
char *cenv[100];
char *token, *value;
i = 0; j = 0;
while(environ[i])
{
	cenv[i] = malloc (sizeof(char) * 2000);
	strcpy(cenv[i], environ[i]);
	i++;
}


i = 0;
 	while (cenv[i])
	{
		token = strtok(cenv[i], "=");
		value = strtok(NULL, " ");
	if(strcmp(name, token) == 0)
	{
		j = 1;
		break;
	}
	i++;
	}
i = 0;
while (cenv[i])
{
	free(cenv[i]);
	i++;
}
	if (j)
	return (value);
	return ("nil");
}

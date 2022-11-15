#include "main.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
char* findpath(char *cmnd)
{
int i, q, j;
char *token, *ret;
char *path[100];
char *p = _getenv("PATH");
char appending[20]= "/";
char *append = _strcat(appending, cmnd);
 i = 0;
token = strtok(p, ":");

while(token)
{
	path[i] = strdup(token);
	token = strtok(NULL, ":");
	i++;
}
path[i] = NULL;
i = 0;
j = 0;
ret = malloc (sizeof(char) * 100);
while (path[i] != NULL)
{
	path[i] = _strcat(path[i], append);
	q = access(path[i], F_OK);
	if (q == 0)
	{
		j = i;
		ret = strcpy(ret, path[i]);
		break;
	}
	i++;
}

/*i = 0;
while (path[i])
{
	free(path[i]);
	i++;
}*/

if (j)
return (ret);
return (NULL);
}

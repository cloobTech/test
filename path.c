#include "main.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

char* findpath(char *cmnd);
int main()
{
//	char *t;
	int i = 0;
	char *p[] = {"boy", "house", "girl", "boss"};
	
	while (p[i])  
	{
	//p[i] = strcat(p[i], "ss");
	printf("%s\n", p[i]);
	i++;
	}
/*	t = findpath("ls");
	if (strcmp(t,"house")==0)
	printf("%s\n", t);*/
	return(0);
}
/*char* findpath(char *cmnd)
{
int i;
char *token;
char *path[100];
char *p = _getenv("PATH");
char appending[20]= "/";
char *append = _strcat(appending, cmnd);
 i = 0;
token = strtok(p, ":");
while(token)
{
	path[i] = token;
	token = strtok(NULL, ":");
//	printf("%s\n", path[i]);
	i++;
}
i = 0;
while (path[i])
{
	path[i] = _strcat(path[i], append);		 
	printf("%s\n", path[i]);
//	q = access(path[i], F_OK);
//	printf("%d\n", q);
	i++;
}
return ("good");
}*/

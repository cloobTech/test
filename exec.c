#include "main.h"
#include <stdio.h>

int main()
{
	char *p;
	p = findpath("pwd");
	printf("%s\n", p);
	return (0);
}

#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int main(int argc, char **argv)
{
        ssize_t read_line;
        char *token, *buffer = NULL;
        size_t n = 0;
	int i, k, status;
	char *args[100];
	char *ar[100];
	pid_t pid;

        read_line = 0;
	while (read_line != -1)
        {
		i = 0;
		printf("#Cisfun$ ");
		read_line = getline(&buffer, &n, stdin);
		token = strtok(buffer, "\n");
		token = strtok(token, " ");
		while(token)
		{
			args[i] = token;
			token = strtok(NULL, " ");
			i++;
		}
		args[i] = NULL;
		pid = fork();
		if (pid == 0)
		{
			k = execv(args[0], args);
			if (k == -1)
				printf("%s: Command not foundi\n", argv[0]);
		}
		wait(&status);

        }

        return (0);
}


#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int main(int __attribute__((unused)) argc, char **argv, char **env)
{
        ssize_t read_line;
        char *token, *buffer = NULL;
        size_t n = 0;
	int i, k, status;
	char *args[100];
	pid_t pid;

        read_line = 0;
	while (1)
        {
		i = 0;
		printf("#Cisfun$ ");
		read_line = getline(&buffer, &n, stdin);
		if (read_line == -1)
		{
			printf("logout\n");
			return (0);
		}
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
			k = execve(args[0], args, env);
			if (k == -1)
				printf("%s: Command not found\n", argv[0]);
		}
		else
		wait(&status);

        }

        return (0);
}

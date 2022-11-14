#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int main(int __attribute__((unused)) argc, char **argv)
{
        ssize_t read_line;
        char *token, *buffer = NULL;
        size_t n = 0;
	int i, k, status, terminal;
	char *args[100];
	pid_t pid;

        read_line = 0;
	terminal = 1;
	while (terminal)
        {
		i = 0;
		terminal = isatty(STDIN_FILENO);
		write(STDOUT_FILENO, "#Cisfun$ ", 10);
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
			k = execvp(args[0], args);
			if (k == -1)
				printf("%s: Command not found\n", argv[0]);
		}
		else
		wait(&status);

        }

        return (0);
}

#include "shell.h"

/**
 * main - creates a shell program
 *
 * Return: Nothing (0)
 */

char **split_tokens(char *str) {
	char **arguments = malloc(sizeof(char *) * (MAX_ARGS + 1));
	if (!arguments) {
		perror("malloc error");
		exit(EXIT_FAILURE);
	}

	char *token;
	int counter = 0;
	const char *delimiter = " \t\n";

	token = strtok(str, delimiter);
	while (token != NULL && counter < MAX_ARGS) {
		arguments[counter++] = strdup(token);
		token = strtok(NULL, delimiter);
	}
	arguments[counter] = NULL;

	return arguments;
}

int main(void)
{
	char *prompt = "#myShell$ ", *buffer = NULL, **args, *path;
	size_t size = BUFF_SIZE;
	ssize_t str_read;
	bool pipe_input = false;
	pid_t pid;

	while (1 && !pipe_input)
	{
		if (isatty(STDIN_FILENO) == 0)
			pipe_input = true;
		else
			write(STDOUT_FILENO, prompt, 10);
		str_read = getline(&buffer, &size, stdin);
		if (str_read == -1)
		{
			perror("Error");
			free(buffer);
			exit(1);
		}
		if (buffer[str_read - 1] == '\n')
			buffer[str_read - 1] = '\0';

		args = split_tokens(buffer);
		path = args[0];
		pid = fork();
		if (pid == 0)
		{
			if ((execve(path, args, NULL)) == -1)
			{
				perror("./shell");
				_exit(1);
			}
		}
		if (pid > 0)
		{
			wait(NULL);
		}
	}
	free(buffer);
	return (0);
}

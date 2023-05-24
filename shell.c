#include "shell.h"

 /**
 * sig_handler - checks if Ctrl C is pressed
 * @sig_num: int
 */

void sig_handler(int sig_num)
{
	if (sig_num == SIGINT)
	{
		_puts("\n#cisfun$ ");
	}
}

 /**
 * _EOF - handles the End of File
 * @len: return value of getline function
 * @buff: buffer
 */

void _EOF(int len, char *buff)
{
	(void)buff;
	if (len == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			_puts("\n");
			free(buff);
		}
		exit(0);
	}
}




 /**
  * _isatty - checks if terminal
  */

void _isatty(void)
{
	if (isatty(STDIN_FILENO))
		_puts("#cisfun$ ");
}


/**
 * main - creates a shell program
 *
 * Return: Nothing (0)
 */

int main(void)
{
	char *prompt = "#myShell$ ";
	char *buffer = NULL;
	char **args;
	char *path;
	size_t size = BUFF_SIZE;
	ssize_t str_read;
	bool pipe_input = false;

	signal(SIGINT, sig_handler);
	_isatty();

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
		
		if (strcmp(path, "exit") == 0)
        	{
            		free(buffer);
            		exit(0);
        	}		

		pid = fork();
		if (pid == -1)
		{
			perror("Error");
			exit(1);
		}
		if (pid == 0)
		{
			if (execve(path, args, NULL) == -1)
			{
				perror("./shell");
				free(buffer);
				exit(1);
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

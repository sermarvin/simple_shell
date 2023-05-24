#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>
#include <stdbool.h>

#define BUFF_SIZE 1024
#define MAX_ARGS 10

char **split_tokens(char *str);

#endif /* _SHELL_H_ */

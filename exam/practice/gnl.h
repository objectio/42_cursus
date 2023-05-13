#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int ft_strlen(char *str);

char *ft_strdup(char *str);

char *get_next_line(int fd);

#endif
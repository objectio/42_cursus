#include "gnl.h"

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

char *ft_strdup(char *str)
{
	int len = ft_strlen(str);
	int i = -1;
	char *dup = malloc(len + 1);

	if (!dup)
		return (NULL);
	while (str[++i])
		dup[i] = str[i];
	return dup;
}

char *get_next_line(int fd)
{
	char buffer;
	char rtn[7000000];
	int i = 0;
	int n;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	n = read(fd, &buffer, 1);
	while (n > 0)
	{
		rtn[i++] = buffer;
		if (buffer == '\n')
			break;
		n = read(fd, &buffer, 1);
	}
	rtn[i] = 0;
	if (n <= 0 && i == 0)
		return (0);
	return ft_strdup(rtn);
}

int main()
{
    int fd;
    fd = open("foo.txt",O_RDONLY);
    char *t;
    t = get_next_line(fd);
    while (t != NULL)
    {
        printf("%s",t);
        t = get_next_line(fd);
    }
    free(t);
    close(fd);

}
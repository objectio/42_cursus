#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main()
{
	int fd;
	char *string;

	if (!(fd = open("gnl.txt", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	printf("%d", fd);
	while (NULL != (string = get_next_line(fd)))
	{
		printf("%s", string);
	}
	close(fd);
	return (0);
}

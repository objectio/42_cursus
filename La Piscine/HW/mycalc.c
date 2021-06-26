#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int		main(int argc, char **argv)
{
	int result = 0;
	int num = 0;
	char c;

	if (argc == 1)
	{
		fprintf(stderr, "usage : mycalc numbers...");
		exit(-1);
	}
	while (--argc)
	{
		num = atoi(argv[argc]);
		result = result + num;
	}
	printf("%d", result);
}

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int		main(int argc, char **argv)
{
	int fp, fnp;
	ssize_t nread;
	char buf[1024];

	if (argc != 3)
	{
		fprintf(stderr, "usage : mycp file1 file2");
		exit(-1);
	}
	if ((fp = open(argv[1], O_RDONLY)) < 0)
	{
		perror(argv[1]);
		exit(-1);
	}
	if ((fnp = open(argv[2], O_WRONLY | O_EXCL,0644 | O_CREAT)) < 0)
	{
		fprintf(stderr, "파일 %s가 이미 존재합니다.", argv[2]);
		exit(-1);
	}
	while ((nread = read(fp, buf, 1024)) > 0)
	{
		if (write(fnp, buf, nread) < nread) 
		{
			break;
		}
	}

	close(fp);
	close(fnp);

	return 0;
}

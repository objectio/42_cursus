#include <unistd.h>

int main(int argc, char **argv)
{
	char marker[255];
	int i = -1;

	if (argc == 3)
	{
		while (argv[1][++i])
		{
			if (marker[(unsigned char)argv[1][i]] != 1)
			{
				write(1, &argv[1][i], 1);
				marker[(unsigned char)argv[1][i]] = 1;
			}
		}
		int j = -1;
		while (argv[2][++j])
		{
			if (marker[(unsigned char)argv[2][j]] != 1)
			{
				write(1, &argv[2][j], 1);
				marker[(unsigned char)argv[2][j]] = 1;
			}
		}
	}

	write(1, "\n", 1);
	return 0;
}
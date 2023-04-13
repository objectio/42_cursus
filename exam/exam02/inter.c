#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv) {
	char marker[255];
	int i = -1;

	if (argc == 3) {
		while (argv[1][++i])
		{
			int j = -1;
			while (argv[2][++j])
			{
				if ((argv[1][i] == argv[2][j]) && (marker[(unsigned char)argv[1][i]] != 1))
				{
					write(1, &argv[1][i], 1);
					marker[(unsigned char)argv[1][i]] = 1;
				}
			}
		}
	}
	write(1, "\n", 1);
	return 0;
}
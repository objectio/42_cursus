#include "header.h"

void	strtoi(char* str, int** conditions)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (i < N)
	{
		while (j < N)
		{
			if (str[k] != '\0')
			{
				if (str[k] != ' ')
				{
					conditions[i][j] = *str - '0';
					j++;
				}
				str++;
			}
		}
		j = 0;
		i++;
	}
}
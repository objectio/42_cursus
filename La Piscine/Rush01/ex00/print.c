#include "header.h"

void	print_answer(int* answer)
{
	int	i;

	i = 1;
	while (*answer != '\0')
	{
		*answer = *answer + '0';
		write(1, answer, 1);
		if (i % 4 != 0)
		{
			write(1, " ", 1);
		}
		else
		{
			write(1, "\n", 1);
		}
		i++;
		answer++;
	}
}
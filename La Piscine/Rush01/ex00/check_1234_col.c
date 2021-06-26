#include "header.h"

int		check_1234_col_1of4(int index, int* answer)
{
	int	i;

	i = 1;
	while (i < 4)
	{
		if (answer[index] == answer[index + (i * N)])
		{
			answer[index] = 0;
			return (0);
		}
		i++;
	}
	return (1);
}

int		check_1234_col_2of4(int index, int* answer)
{
	int	i;

	i = 1;
	if (answer[index] == answer[index - (i * N)])
	{
		answer[index] = 0;
		return (0);
	}
	while (i < 3)
	{
		if (answer[index] == answer[index + (i * N)])
		{
			answer[index] = 0;
			return (0);
		}
		i++;
	}
	return (1);
}

int		check_1234_col_3of4(int index, int* answer)
{
	int	i;

	i = 1;
	if (answer[index] == answer[index + (i * N)])
	{
		answer[index] = 0;
		return (0);
	}
	while (i < 3)
	{
		if (answer[index] == answer[index - (i * N)])
		{
			answer[index] = 0;
			return (0);
		}

		i++;
	}
	return (1);
}

int		check_1234_col_4of4(int index, int* answer)
{
	int	i;

	i = 1;
	while (i < 4)
	{
		if (answer[index] == answer[index - (i * N)])
		{
			answer[index] = 0;
			return (0);
		}
		i++;
	}
	return (1);
}

int		check_1234_col(int index, int* answer)
{
	int	i;

	if (index / N == 0)
	{
		if (check_1234_col_1of4(index, answer) == 0)
			return (0);
	}

	if (index / N == 1)
	{
		if (check_1234_col_2of4(index, answer) == 0)
			return (0);
	}

	if (index / N == 2)
	{
		if (check_1234_col_3of4(index, answer) == 0)
			return (0);
	}
	if (index / N == 3)
	{
		if (check_1234_col_4of4(index, answer) == 0)
			return (0);
	}
	return (1);
}
#include "header.h"

int		check_1234_row_1of4(int index, int* answer)
{
	int	i;

	i = 1;
	while (i < 4)
	{
		if (answer[index] == answer[index + i])
		{
			answer[index] = 0;
			return (0);
		}
		i++;
	}
	return (1);
}

int		check_1234_row_2of4(int index, int* answer)
{
	int	i;

	i = 1;
	if (answer[index] == answer[index - i])
	{
		answer[index] = 0;
		return (0);
	}
	while (i < 3)
	{
		if (answer[index] == answer[index + i])
		{
			answer[index] = 0;
			return (0);
		}
		i++;
	}
	return (1);
}

int		check_1234_row_3of4(int index, int* answer)
{
	int	i;

	i = 1;
	if (answer[index] == answer[index + i])
	{
		answer[index] = 0;
		return (0);
	}
	while (i < 3)
	{
		if (answer[index] == answer[index - i])
		{
			answer[index] = 0;
			return (0);
		}
		i++;
	}
	return (1);
}

int		check_1234_row_4of4(int index, int* answer)
{
	int	i;

	i = 1;
	while (i < 4)
	{
		if (answer[index] == answer[index - i])
		{
			answer[index] = 0;
			return (0);
		}
		i++;
	}
	return (1);
}


int		check_1234_row(int index, int* answer)
{
	if (index % N == 0)
	{
		if (check_1234_row_1of4(index, answer) == 0)
			return (0);
	}
	if (index % N == 1)
	{
		if (check_1234_row_2of4(index, answer) == 0)
			return (0);
	}
	if (index % N == 2)
	{
		if (check_1234_row_3of4(index, answer) == 0)
			return (0);
	}
	if (index % N == 3)
	{
		if (check_1234_row_4of4(index, answer) == 0)
			return (0);
	}
	return (1);
}
#include "header.h"

int	get_box(int index, int** conditions, int* answer)
{
	int	i;

	if (index == N * N)
		return (1);
	i = 1;
	while (i <= N)
	{
		answer[index] = i;
		i++;
		if (check_1234_row(index, answer) == 0)
			continue;
		if (check_1234_col(index, answer) == 0)
			continue;
		if (check_udlr(index, conditions, answer) == 0)
			continue;
		if (get_box(index + 1, conditions, answer))
			return (1);
	}
	return (0);
}

void	get_up_value(int index, int** conditions, int* answer, int* up_value)
{
	int	i;
	int	temp;

	*up_value = 1;
	i = 2;
	temp = answer[index - (N - 1) * N];
	while (i >= 0)
	{
		if (temp < answer[index - (i * N)])
		{
			temp = answer[index - (i * N)];
			(*up_value)++;
		}
		i--;
	}
}

void	get_down_value(int index, int** conditions, int* answer, int* down_value)
{
	int	i;
	int	temp;

	*down_value = 1;
	i = 1;
	temp = answer[index];
	while (i <= N - 1)
	{
		if (temp < answer[index - (i * N)])
		{
			temp = answer[index - (i * N)];
			(*down_value)++;
		}
		i++;
	}
}

void	get_left_value(int index, int** conditions, int* answer, int* left_value)
{
	int	i;
	int	temp;

	*left_value = 1;
	i = 1;
	temp = answer[index + 1 - N];
	while (i <= N - 1)
	{
		if (temp < answer[index + 1 - N + i])
		{
			temp = answer[index + 1 - N + i];
			(*left_value)++;
		}
		i++;
	}
}

void	get_right_value(int index, int** conditions, int* answer, int* right_value)
{
	int	i;
	int	temp;

	*right_value = 1;
	i = 1;
	temp = answer[index];
	while (i <= N - 1)
	{
		if (temp < answer[index - i])
		{
			temp = answer[index - i];
			(*right_value)++;
		}
		i++;
	}
}
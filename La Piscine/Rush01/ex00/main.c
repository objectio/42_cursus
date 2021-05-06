#include "header.h"

int	main(int argc, char* argv[])
{
	int 	result;
	int* answer;
	int** conditions;
	int	i;

	answer = (int*)malloc(sizeof(int) * N * N);
	conditions = (int**)malloc(sizeof(int*) * N);
	i = 0;
	while (i < N)
		conditions[i++] = (int*)malloc(sizeof(int) * N);
	strtoi(argv[1], conditions);
	if (check_exception(conditions, argc) == 1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	i = 0;
	while (i < N * N)
		answer[i++] = 0;
	result = get_box(0, conditions, answer);
	if (result == 1)
		print_answer(answer);
	else
		write(1, "Error\n", 6);
	free_memory(conditions, answer);
	return (0);
}
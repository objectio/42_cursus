#ifndef HEADER_H
#define HEADER_H
#include <unistd.h>
#include <stdlib.h>
# define N 4

int		check_exception(int** conditions, int argc);
void	strtoi(char* str, int** conditions);
int		check_1234_row_1of4(int index, int* answer);
int		check_1234_row_2of4(int index, int* answer);
int		check_1234_row_3of4(int index, int* answer);
int		check_1234_row_4of4(int index, int* answer);
int		check_1234_row(int index, int* answer);
int		check_1234_col_1of4(int index, int* answer);
int		check_1234_col_2of4(int index, int* answer);
int		check_1234_col_3of4(int index, int* answer);
int		check_1234_col_4of4(int index, int* answer);
int		check_1234_col(int index, int* answer);
void	get_left_value(int index, int** conditions, int* answer, int* left_value);
void	get_right_value(int index, int** conditions, int* answer, int* right_value);
int		check_left_right(int index, int** conditions, int* answer);
void	get_up_value(int index, int** conditions, int* answer, int* up_value);
void	get_down_value(int index, int** conditions, int* answer, int* down_value);
int		check_up_down(int index, int** conditions, int* answer);
int		check_udlr(int index, int** conditions, int* answer);
int		get_box(int index, int** conditions, int* answer);
void	print_answer(int* answer);
void	free_memory(int** conditions, int* answer);

#endif
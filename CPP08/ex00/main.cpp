/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 01:45:40 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/23 01:45:40 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#define MAX_VAL 500

int main(int ac, char **av)
{
	int find;

	if (ac != 2)
		std::cout << av[0] << ": need one argument, a number between 1 and " << MAX_VAL << std::endl;
	else if ((find = std::atoi(av[1])) < 1 || find > MAX_VAL)
		std::cout << av[0] << ": the number is not between 1 and " << MAX_VAL << std::endl;
	else
	{
		std::srand(time(NULL));
		std::vector<int> container(MAX_VAL);
		for (int i = 0; i < MAX_VAL; i++)
			container[i] = (std::rand() % MAX_VAL) + 1;
		{
			std::deque<int> numbers(container.begin(), container.end());
			easyfind(numbers, find);
		}
		{
			std::vector<int> numbers(container);
			easyfind(numbers, find);
		}
		{
			std::list<int> numbers(container.begin(), container.end());
			easyfind(numbers, find);
		}
		return (0);
	}
	return (1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:18:18 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/22 12:18:27 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	{
		Form form("Enrollment certificate", 10, 10);
		Bureaucrat max("Max Senges", 7);
		std::cout << max;
		std::cout << form;
		max.signForm(form);
		std::cout << form;
	}

	{
		Form form("Enrollment certificate", 100, 100);
		Bureaucrat jan("Jan Behrenbeck", 142);
		std::cout << jan;
		std::cout << form;
		jan.signForm(form);
	}

	{
		try
		{
			Form form("Form", 0, 0);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	{
		try
		{
			Form form("Form", 160, 160);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}
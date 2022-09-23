/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 02:24:41 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/22 11:48:01 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "default wrong animal constructor called\n";
    this->type = "wrong animal";
}

WrongAnimal::WrongAnimal(std::string type)
{
    std::cout << "naming wrong animal constructor called" << std::endl;
    this->type = type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy)
{
    std::cout << "Overloaded copy assignement operator used\n";
    this->type = copy.type;
    return (*this);
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
    std::cout << "wrong animal copy constructor called" << std::endl;
    this->type = copy.type;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "wrong animal destructor called" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (this->type);
}

void WrongAnimal::makeSound() const
{
    std::cout << "meta sound" << std::endl;
}
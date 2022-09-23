/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 01:51:01 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/22 11:41:14 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
    std::cout << "default animal constructor called" << std::endl;
    this->type = "animal";
}

Animal::Animal(std::string type)
{
    std::cout << "naming animal constructor called" << std::endl;
    this->type = type;
}

Animal::~Animal() {
    std::cout << "Destructor for Animal" << std::endl;
}

Animal::Animal(const Animal& copy)
{
    this->type = copy.type;
}

Animal& Animal::operator=(const Animal& copy)
{
    this->type = copy.type;
    return (*this);
}

void Animal::makeSound() const {
    std::cout << "Meta sound" << std::endl;
}

std::string Animal::getType() const {
    return type;
}
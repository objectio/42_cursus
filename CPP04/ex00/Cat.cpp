/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 02:20:18 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/22 11:44:25 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") 
{
    std::cout << "default cat constructor called" << std::endl;
}

Cat::Cat(const Cat& copy) : Animal("cat")
{
    std::cout << "copy cat constructor called" << std::endl;
    this->type = copy.type;
}

Cat::~Cat()
{
    std::cout << "cat destructor called" << std::endl;
}


Cat &Cat::operator=(const Cat& copy)
{
    this->type = copy.type;
    return (*this);
}

void    Cat::makeSound(void) const
{
    std::cout << "Meow" << std::endl;
}

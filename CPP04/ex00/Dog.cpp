/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 02:21:50 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/22 11:45:06 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
    std::cout << "default dog constructor called" << std::endl;
}

Dog::Dog(const Dog& copy) : Animal("cat")
{
    std::cout << "copy dog constructor called" << std::endl;
    this->type = copy.type;
}

Dog &Dog::operator=(const Dog& copy)
{
    this->type = copy.type;
    return (*this);
}

Dog::~Dog() {
    std::cout << "Destructor for Dog" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof" << std::endl;
}

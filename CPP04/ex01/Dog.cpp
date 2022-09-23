/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 02:21:50 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/21 11:44:11 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog") 
{
    std::cout << "default dog constructor called" << std::endl;
    this->brain = new Brain();
}

Dog::Dog(const Dog& copy) : Animal("Dog")
{
    std::cout << "copy dog constructor called" << std::endl;
    this->brain = new Brain(*(copy.brain));
    this->type = copy.type;
}

Dog::~Dog()
{
    std::cout << "dog destructor called" << std::endl;
    delete (this->brain);
}

Dog &Dog::operator=(const Dog& copy)
{
    std::cout << "dog copy assignement operator called" << std::endl;
    if (this->brain)
        delete(brain);
    this->brain = new Brain(*(copy.brain));
    this->type = copy.type;
    return (*this);
}

void    Dog::makeSound(void) const
{
    std::cout << "Woof" << std::endl;
}

void    Dog::showThoughts() const
{
    this->brain->showThoughts();
}
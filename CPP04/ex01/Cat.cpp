/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 02:20:18 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/21 17:00:28 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "default cat constructor called" << std::endl;
    this->brain = new Brain();
}

Cat::Cat(const Cat& copy) : Animal("Cat")
{
    std::cout << "copy cat constructor called" << std::endl;
    this->brain = new Brain(*(copy.brain));
    this->type = copy.type;
}

Cat &Cat::operator=(const Cat& copy)
{
    std::cout << "copy cat assignement operator called" << std::endl;
    if (this->brain)
        delete(this->brain);
    this->brain = new Brain(*(copy.brain));
    this->type = copy.type;
    return (*this);
}

Cat::~Cat() {
    std::cout << "Destructor for Cat" << std::endl;
    delete(this->brain);
}

void Cat::makeSound() const {
    std::cout << "Meow" << std::endl;
}

void    Cat::showThoughts() const
{
    this->brain->showThoughts();
}
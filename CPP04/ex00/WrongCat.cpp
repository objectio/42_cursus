/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 02:26:02 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/22 11:48:56 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") 
{
    std::cout << "default wrong cat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal("cat")
{
    std::cout << "wrong cat copy constructor called" << std::endl;
    this->type = copy.type;
}

WrongCat::~WrongCat()
{
    std::cout << "wrong cat destructor called" << std::endl;
}


WrongCat &WrongCat::operator=(const WrongCat& copy)
{
    this->type = copy.type;
    return (*this);
}

void    WrongCat::makeSound(void) const
{
    std::cout << "Meow!" << std::endl;
}
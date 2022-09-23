/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 22:59:44 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/13 23:47:06 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
    this->name = "zombie";
}

void    	Zombie::setName(std::string str)
{
    this->name = str;
}

std::string	Zombie::getName()
{
    return (this->name);
}

void    	Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ. . ." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << this->name << " is destroyed." << std::endl;
}
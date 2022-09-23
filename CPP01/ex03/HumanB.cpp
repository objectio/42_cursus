/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 17:46:43 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/14 21:13:27 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string humanB_name) : name(humanB_name), weapon(NULL)
{
}

HumanB::HumanB(std::string humanB_name, Weapon humanB_weapon)
{
    this->name = humanB_name;
    this->weapon = &humanB_weapon;
}

void    HumanB::attack()
{
    std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

void    HumanB::setWeapon(Weapon &humanB_weapon)
{
    this->weapon = &humanB_weapon;
}

HumanB::~HumanB()
{}
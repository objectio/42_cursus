/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:21:42 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/19 20:24:05 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() 
{
    std::cout << "Default ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) 
{
    this->setName(name);
    this->setHitPoint(100);
    this->setEnergyPoint(50);
    this->setAttackDamage(20);
    std::cout << "ScavTrap constructor called for " << getName() << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& s)
{
    *this = s;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& s)
{
    (void)s;
    return *this;
}

ScavTrap::~ScavTrap() 
{
    std::cout << "ScavTrap destructor called for " << getName() << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (getEnergyPoint() > 0) {
        std::cout << "ScavTrap " << getName() << " attacks " << target << " causing " << getAttackDamage() << " points of damage!" << std::endl;
        setEnergyPoint(getEnergyPoint() - 1);
    }
    else
        std::cout << getName() << " can't do anything." << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << getName() << " is now in Gate keeper mode." << std::endl;
}
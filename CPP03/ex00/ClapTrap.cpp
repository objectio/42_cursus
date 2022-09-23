/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:42:21 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/19 18:46:55 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() 
{
    std::cout << "Default constructor ClapTrap called" << std::endl;

	setName("unknown");
    setHitPoint(0);
    setEnergyPoint(0);
    setAttackDamage(0);
}

ClapTrap::ClapTrap(std::string name) 
{
    std::cout << "Constructor ClapTrap called for " << name << std::endl;

    setName(name);
    setHitPoint(10);
    setEnergyPoint(10);
    setAttackDamage(0);
}

ClapTrap::ClapTrap(const ClapTrap& c)
{
	*this = c;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& c)
{
	setName(c.name);
	setHitPoint(c.hitPoint);
    setEnergyPoint(c.energyPoint);
    setAttackDamage(c.attackDamage);
	return *this;
}

ClapTrap::~ClapTrap() 
{
    std::cout << "Destructor ClapTrap called for " << name << std::endl;
}

void ClapTrap::setName(std::string name) 
{
	this->name = name;
}

void ClapTrap::setHitPoint(int hitPoint) 
{
	this->hitPoint = hitPoint;
}

void ClapTrap::setEnergyPoint(int energyPoint) 
{
	this->energyPoint = energyPoint;
}

void ClapTrap::setAttackDamage(int attackDamage) 
{
	this->attackDamage = attackDamage;
}

std::string ClapTrap::getName() 
{
	return name;
}

int ClapTrap::getHitPoint() 
{
	return hitPoint;
}

int ClapTrap::getEnergyPoint() 
{
	return energyPoint;
}

int ClapTrap::getAttackDamage() 
{
	return attackDamage;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->energyPoint > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoint--;
	}
	else {
		std::cout << this->name << " can't do anything. " << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoint - amount <= 0) 
	{
		delete this;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " have taken damage, losing " << amount << " hit points." << std::endl;
	this->hitPoint -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoint > 0) {
		std::cout << "ClapTrap " << this->name << " be repaired, getting " << amount << " hit points back." << std::endl;
		this->hitPoint += amount;
		this->energyPoint--;
	}
	else {
		std::cout << this->name << " can't do anything. " << std::endl;
	}
}
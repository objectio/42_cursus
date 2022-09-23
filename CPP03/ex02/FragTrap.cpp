/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:24:12 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/19 20:38:53 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() 
{
    std::cout << "Default FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) {
    setName(name);
    setHitPoint(100);
    setEnergyPoint(100);
    setAttackDamage(30);
    std::cout << "FragTrap constructor called for " << getName() << std::endl;
}

FragTrap::FragTrap(const FragTrap& f)
{
    *this = f;
}

FragTrap& FragTrap::operator=(const FragTrap& f)
{
    (void)f;
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor called for " << getName() << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "High five!" << std::endl;
}
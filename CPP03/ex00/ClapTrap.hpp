/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:42:13 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/19 18:41:56 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
	private:
	std::string name;
	int hitPoint;
	int energyPoint;
	int attackDamage;

	public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& c);
	ClapTrap& operator=(const ClapTrap& c);
	~ClapTrap();
	void setName(std::string name);
    void setHitPoint(int hitPoints);
    void setEnergyPoint(int energyPoints);
    void setAttackDamage(int attackDamage);
    std::string getName();
    int getHitPoint();
    int getEnergyPoint();
    int getAttackDamage();
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif
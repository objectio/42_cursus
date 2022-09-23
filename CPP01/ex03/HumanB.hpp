/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 17:46:33 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/14 19:49:55 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB {
    private:
    std::string name;
    Weapon *weapon;

    public:
    HumanB(std::string humanB_name);
    HumanB(std::string humanB_name, Weapon humanB_weapon);
    void        attack();
    void        setWeapon(Weapon &humanB_weapon);
    ~HumanB();
};

#endif
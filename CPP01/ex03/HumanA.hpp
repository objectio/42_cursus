/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 03:45:33 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/14 21:16:21 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA {
    private:
    std::string name;
    Weapon &weapon;

    public:
    HumanA(std::string humanA_name, Weapon &humanA_weapon);
    void        attack();
    ~HumanA();
};

#endif
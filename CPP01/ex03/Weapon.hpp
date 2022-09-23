/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 03:35:05 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/14 03:51:26 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon {
    private:
    std::string type;

    public:
    Weapon();
    Weapon(std::string name);
    const std::string&  getType();
    void                setType(std::string type_name);
    ~Weapon();
};

#endif
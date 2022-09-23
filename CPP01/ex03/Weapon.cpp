/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 03:38:44 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/14 03:52:44 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
    this->type = "gun";
}

Weapon::Weapon(std::string name)
{
    this->type = name;
}

const std::string&  Weapon::getType()
{
    return (this->type);
}

void                Weapon::setType(std::string type_name)
{
    this->type = type_name;
}

Weapon::~Weapon()
{
}
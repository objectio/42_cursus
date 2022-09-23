/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:23:53 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/19 20:34:47 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

class FragTrap : public virtual ClapTrap {
public:
    FragTrap();
    FragTrap(std::string name);
    FragTrap(const FragTrap& f);
    FragTrap& operator=(const FragTrap& f);
    ~FragTrap();
    void highFivesGuys(void);
};

#endif
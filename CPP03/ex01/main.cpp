/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 18:56:32 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/19 19:02:13 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ScavTrap s1 = ScavTrap("s1");

	s1.takeDamage(20);
    s1.attack("Hoo");
    s1.beRepaired(7);
	s1.guardGate();

	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 20:34:54 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/19 20:37:43 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	FragTrap f1 = FragTrap("f1");

	f1.takeDamage(50);
    f1.attack("Zoo");
    f1.beRepaired(2);
	f1.highFivesGuys();

	return (0);
}
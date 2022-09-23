/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:42:03 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/19 18:39:03 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap c1 = ClapTrap("c1");
    
    c1.takeDamage(7);
    c1.attack("Foo");
    c1.beRepaired(4);

	return (0);
}
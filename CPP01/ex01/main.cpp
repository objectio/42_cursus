/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 22:37:16 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/14 00:48:42 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int main(void)
{
    Zombie* zombies = zombieHorde(6, "Joy");

    for (int i = 0; i < 6; i++)
        zombies[i].announce();

    delete[] zombies;
    return (0);
}
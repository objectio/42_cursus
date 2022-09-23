/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 21:03:43 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/17 17:44:26 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int main(void)
{
    Zombie* James = newZombie("James");
    Zombie* Harry = newZombie("Harry");
    (*James).announce();
    (*Harry).announce();
    
    delete James;
    delete Harry;

    randomChump("Chandler");
    randomChump("Monika");
    
    return (0);
}
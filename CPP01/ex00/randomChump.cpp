/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 17:38:12 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/13 21:58:53 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

void    randomChump(std::string name)
{
    Zombie new_zombie;
    new_zombie.setName(name);

    new_zombie.announce();
}
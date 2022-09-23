/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 22:38:10 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/13 23:46:31 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
    private:
    std::string name;

    public:
    Zombie* horde;
    Zombie();
    void        setName(std::string str);
    std::string getName();
    void        announce(void);
    ~Zombie();
};

#endif
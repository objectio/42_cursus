/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 01:48:28 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/21 11:08:03 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
    protected:
    std::string type;

    public:
    Animal();
    Animal(std::string type);
    Animal(const Animal& copy);
    Animal& operator=(const Animal& copy);
    virtual ~Animal();
    virtual void makeSound() const;
    std::string getType() const;
};

#endif
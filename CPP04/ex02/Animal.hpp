/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 18:39:33 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/21 18:39:43 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
    protected:
        Animal();
        Animal(std::string type);
        Animal(const Animal& tocopy);
        Animal &operator=(const Animal &toCopy);
        std::string type;
    public:
        virtual ~Animal();
        std::string getType() const;
        virtual void    makeSound(void) const = 0; // pure virtual function = abstract class
};

#endif
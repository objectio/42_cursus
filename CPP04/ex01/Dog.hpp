/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 02:20:53 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/21 11:42:39 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Cat.hpp"
#include "Brain.hpp"

class Dog : public Animal {
    private:
    Brain *brain;

    public:
    Dog();
    Dog(const Dog& copy);
    Dog &operator=(const Dog& copy);
    ~Dog();
    void makeSound() const;
    void showThoughts() const;
};

#endif
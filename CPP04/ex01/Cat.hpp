/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 01:51:39 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/21 11:44:54 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
    private :
    Brain *brain;

    public:
    Cat();
    Cat(const Cat& copy);
    Cat &operator=(const Cat& copy);
    ~Cat();
    void makeSound() const;
    void showThoughts() const;
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 01:51:39 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/21 11:13:15 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
    public:
    Cat();
    Cat(const Cat& copy);
    Cat &operator=(const Cat& copy);
    ~Cat();
    void makeSound() const;
};

#endif
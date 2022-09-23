/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 18:43:06 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/22 16:24:56 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
    Cat *cat = new Cat();
    Cat *newCat = new Cat(*cat);

    std::cout << cat->getType() << std::endl;
    std::cout << newCat->getType() << std::endl;
    
    cat->showThoughts();
    newCat->showThoughts();

    delete cat;
    delete newCat;

    const Animal* j = new Dog();
 	const Animal* i = new Cat();
 	delete j;//should not create a leak
 	delete i;

    const Animal *animals[10];
    for (int i = 0; i <= 4; i++)
        animals[i] = new Dog();
    for (int i = 5; i <= 9; i++)
        animals[i] = new Cat();
    for (int i = 0; i <= 9; i++)
    {
        std::cout << animals[i]->getType() << std::endl;
        animals[i]->makeSound();
    }
    for (int i = 0; i <= 9; i++)
        delete animals[i];
    return (0);
}   
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 11:39:32 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/22 16:07:49 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <string>
#include <stdlib.h>

Brain::Brain()
{
    std::cout << "Brain constructor called" << std::endl;

    this->ideas = new std::string[100];
    for (int i = 0; i <= 99; i++)
    {
        this->ideas[i] = (std::string)"idea number " += (i/10) + 48; 
        this->ideas[i] += (i%10) + 48;
    }
}

Brain::Brain(const Brain &copy)
{
    std::cout << "brain copy constructor called" << std::endl;

    this->ideas = new std::string[100];
    for (int i = 0; i <= 99; i++)
        this->ideas[i] = copy.ideas[i];
}

Brain&    Brain::operator=(const Brain &copy)
{
    std::cout << "brain copy assignement operator called" << std::endl;
    if (this->ideas)
        delete(this->ideas);
    this->ideas = new std::string[100];
    for (int i = 0; i <= 99; i++)
        this->ideas[i] = copy.ideas[i];
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
    delete[] (this->ideas);
}

void    Brain::showThoughts()
{
    for (int i = 0; i <= 5; i++)
        std::cout << this->ideas[i] << std::endl;
}
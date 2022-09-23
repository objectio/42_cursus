/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 18:40:17 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/21 18:40:19 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
    public:
        Brain();
        Brain(const Brain &toCopy);
        ~Brain();
        Brain&    operator=(const Brain &toCopy);
        void    showThoughts();
        std::string *ideas;
};

#endif
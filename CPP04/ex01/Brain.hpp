/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 11:38:44 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/21 11:40:54 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
    public:
    std::string *ideas;
    
    Brain();
    Brain(const Brain &copy);
    ~Brain();
    Brain& operator=(const Brain &copy);
    void showThoughts();
};

#endif
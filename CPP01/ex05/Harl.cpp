/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 00:09:19 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/17 16:59:50 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void    Harl::debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void    Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}
void    Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}
void    Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void    Harl::complain(std::string level)
{
    void (Harl::*ptr[4])(void);
    ptr[0] = &Harl::debug;
    ptr[1] = &Harl::info;
    ptr[2] = &Harl::warning;
    ptr[3] = &Harl::error;

    int check = (level == "DEBUG") || (level == "INFO") || (level == "WARNING") || (level == "ERROR");
    int cal = (level == "DEBUG") * 0 + (level == "INFO") * 1 + (level == "WARNING") * 2 + (level == "ERROR") * 3;

    switch (check)
    {
    case 0:
        std::cout << "I don't know what are you saying." << std::endl;
        break;
    
    case 1:
        (this->*ptr[cal])();
        break;
    
    default:
        break;
    }
}
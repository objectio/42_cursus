/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 18:32:00 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/12 18:59:56 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "phonebook.hpp"
#include "contact.hpp"

int main(void)
{
    PhoneBook   phonebook;
    Contact     contact;
    std::string input;

    while (1)
    {
        std::cout << "Enter a command (ADD or SEARCH or EXIT) : ";
        std::cin >> input;

        if (input == "ADD")
        {
            std::cout << "Enter the first name : ";
            std::cin >> input;
            contact.setFirstName(input);

            std::cout << "Enter the last name : ";
            std::cin >> input;
            contact.setLastName(input);

            std::cout << "Enter the nickname : ";
            std::cin >> input;
            contact.setNickName(input);

            std::cout << "Enter the phone number : ";
            std::cin >> input;
            contact.setPhoneNumber(input);

            std::cout << "Enter the darkest secret : ";
            std::cin >> input;
            contact.setDarkestSecret(input);

            //phonebook.Add();
        }
        else if (input == "SEARCH")
        {
            std::cout << "SEARCH" << std::endl;
        }
        else if (input == "EXIT")
        {
            exit(0);
        }
        else {
            std::cout << "Try again!" << std::endl;
        }   
    }

    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 18:02:05 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/12 18:53:54 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

void Contact::setFirstName(std::string input)
{
	this->FirstName = input;
}

void Contact::setLastName(std::string input)
{
	LastName = input;
}

void Contact::setNickName(std::string input)
{
	NickName = input;
}

void Contact::setPhoneNumber(std::string input)
{
	PhoneNumber = input;
}

void Contact::setDarkestSecret(std::string input)
{
	DarkestSecret = input;
}

std::string Contact::getFirstName()
{
	return (this->FirstName);
}
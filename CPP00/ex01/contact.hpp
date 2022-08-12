/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 10:29:19 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/12 18:46:11 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>

class Contact {
	private:
    std::string	FirstName;
	std::string	LastName;
	std::string	NickName;
	std::string	PhoneNumber;
	std::string	DarkestSecret;

	public:
	void	setFirstName(std::string input);
	void	setLastName(std::string input);
	void	setNickName(std::string input);
	void	setPhoneNumber(std::string input);
	void	setDarkestSecret(std::string input);
	std::string	getFirstName();
};

#endif
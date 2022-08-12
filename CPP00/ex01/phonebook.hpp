/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 18:27:33 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/12 19:07:29 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

#include <iostream>
#include <string>
#include "contact.hpp"

class PhoneBook {
	private:
	Contact	contactArray[8];
	int		cnt;

	public:
	void	Add(Contact newContact);
};

#endif
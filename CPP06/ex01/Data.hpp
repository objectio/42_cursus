/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 13:10:32 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/22 13:10:41 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <stdint.h>
class Data
{
	private :
				unsigned int	_age;
				unsigned int	_nbChild;
	public :
				Data(void);
				Data(unsigned int age, unsigned int nbChild);
				Data(const Data &data);
				virtual ~Data(void);

				unsigned int	getAge(void)const;
				unsigned int	getNbChild(void)const;
			
				Data	&operator=(const Data &Data);
};

#endif
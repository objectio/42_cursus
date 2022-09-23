/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 13:09:52 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/22 13:09:58 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

uintptr_t	serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int	main(void)
{
	Data		*data;
	uintptr_t	serialized;
	Data		*deserialized;

	data = new Data();
	std::cout << "data ptr = " << data << std::endl;
	std::cout << "age   = " << data->getAge() << std::endl;
	std::cout << "Child = " << data->getNbChild() << std::endl << std::endl;

	serialized = serialize(data);
	std::cout << "serialize(data ptr) = " << serialized << std::endl << std::endl;

	deserialized = deserialize(serialized);
	std::cout << "deserialize(data ptr) = " << deserialized << std::endl;
	std::cout << "age   = " << data->getAge() << std::endl;
	std::cout << "Child = " << data->getNbChild() << std::endl << std::endl;

	delete data;
	return (0);
}
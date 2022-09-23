/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 00:59:04 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/14 03:28:57 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str; // 주소값을 통한 간접 참조
    std::string& stringREF = str;  // 직접 참조

    std::cout << "The memory address of the string variable = " << &str << std::endl;
    std::cout << "The memory address held by stringPTR = " << stringPTR << std::endl;
    std::cout << "The memory address held by stringREF = " << &stringREF << std::endl;
    std::cout << std::endl;

    std::cout << "The value of the string variable = " << str << std::endl;
    std::cout << "The value pointed to by stringPTR = " << *stringPTR << std::endl;
    std::cout << "The value pointed to by stringREF = " << stringREF << std::endl;

    return (0);
}
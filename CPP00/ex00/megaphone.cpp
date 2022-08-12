/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 11:46:24 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/08 16:42:44 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

char lowerToUpper(char c)
{
    if ('a' <= c && c <= 'z')
    {
        c = c - 32;
    }
    return (c);
}

int main(int argc, char** argv) {
    int i;

    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
    argv++;
    while (*argv)
    {
        i = 0;
        while ((*argv)[i])
        {
            std::cout << lowerToUpper((*argv)[i]);
            i++;
        }
        argv++;
    }
    std::cout << std::endl;
    return 0;
}
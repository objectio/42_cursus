/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 22:26:43 by younjkim          #+#    #+#             */
/*   Updated: 2022/08/17 17:42:00 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

void    replace(std::string& stream, std::string s1, std::string s2)
{
    for (size_t i = 0; i < stream.size(); i++)
        if (stream.find(s1, i) < stream.size())
        {
            i = stream.find(s1, i);
            stream.erase(i, s1.size());
            stream.insert(i, s2);
            i += s2.size();
        }
}

int main(int argc, char** argv)
{
    if (argc != 4)
    {
        std::cout << "THis program must need 3 arguments. Try again!" << std::endl;
        return (-1);
    }

    std::string fileName;
    std::string stream;
    std::string content;
    std::string s2;

    std::ifstream input(argv[1]);
    fileName = argv[1];
    fileName.append(".replace");

    if (input.fail())
    {
        std::cout << "File does not exist" << std::endl;
        return (-1); 
    }

    while (!input.eof())
    {
        getline(input, stream);
        content.append(stream);
        content.append("\n");
        replace(content, argv[2], argv[3]);
    }
    input.close();

    std::ofstream output(fileName.c_str());

    output << content;
    output.close();
    return (0);
}

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/20 23:54:12 by younjkim          #+#    #+#              #
#    Updated: 2022/08/21 02:29:51 by younjkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Polymorphism

CXX = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp

all: $(NAME)

$(NAME): $(SRC)
	$(CXX) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)

re: clean all
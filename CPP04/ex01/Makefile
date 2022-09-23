# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/20 23:54:29 by younjkim          #+#    #+#              #
#    Updated: 2022/08/21 16:46:01 by younjkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Polymorphism_2

CXX = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Animal.cpp Cat.cpp Dog.cpp Brain.cpp

all: $(NAME)

$(NAME): $(SRC)
	$(CXX) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)

re: clean all
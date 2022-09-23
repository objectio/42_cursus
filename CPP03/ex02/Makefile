# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/19 17:20:07 by younjkim          #+#    #+#              #
#    Updated: 2022/08/19 20:28:02 by younjkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FragTrap

CXX = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

all: $(NAME)

$(NAME): $(SRC)
	$(CXX) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)

re: clean all
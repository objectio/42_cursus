# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/19 16:41:17 by younjkim          #+#    #+#              #
#    Updated: 2022/08/19 17:15:22 by younjkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ClapTrap

CXX = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp ClapTrap.cpp

all: $(NAME)

$(NAME): $(SRC)
	$(CXX) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)

re: clean all
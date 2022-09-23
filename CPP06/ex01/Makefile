# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/22 13:09:11 by younjkim          #+#    #+#              #
#    Updated: 2022/08/22 13:09:33 by younjkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Serialization

CXX = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Data.cpp

all: $(NAME)

$(NAME): $(SRC)
	$(CXX) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)

re: clean all
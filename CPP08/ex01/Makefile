# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 01:44:42 by younjkim          #+#    #+#              #
#    Updated: 2022/08/23 19:33:02 by younjkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Span

CXX = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Span.cpp

all: $(NAME)

$(NAME): $(SRC)
	$(CXX) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)

re: clean all
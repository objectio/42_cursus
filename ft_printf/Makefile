# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/18 10:30:55 by younjkim          #+#    #+#              #
#    Updated: 2022/01/20 16:11:27 by younjkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CM = cc

FLAG = -Wall -Wextra -Werror

SRC = ft_printf.c ft_printf_utils.c ft_printf_utils_2.c

CNVRT = $(SRC:.c=.o)

INCLUDE = ft_printf.h

all: $(NAME)

$(NAME) : $(CNVRT) $(INCLUDE)
	@ar rcs $(NAME) $(CNVRT) $(INCLUDE)

%.o : %.c $(INCLUDE)
	@$(CM) $(FLAG) -o $@ -c $<

clean:
	@rm -rf $(CNVRT)

fclean:	clean
	@rm -rf $(NAME)

re: fclean all

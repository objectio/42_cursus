# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/15 06:21:27 by younjkim          #+#    #+#              #
#    Updated: 2022/09/23 21:43:07 by younjkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	philo
SRCS_DIR			=	./srcs/
HEADER				=	./include/philo.h
SRCS				=	main.c			\
						init.c			\
						utils.c			\
						thread.c		\
						time.c			\
						activity.c		\
						print.c
SRCS_BASENAME		=	$(addprefix $(SRCS_DIR), $(SRCS))
OBJS				=	$(SRCS_BASENAME:.c=.o)
CC					=	clang
FLAGS				=	-Wall -Wextra -Werror -I ./include/ 

.c.o			:
				$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

all				:	$(NAME)

$(NAME)			:	$(OBJS) $(HEADER)
				$(CC) $(FLAGS) $(OBJS) -o $(NAME) -lpthread
				@echo [$(NAME)] : Created !

clean			:
				rm -f $(OBJS)
				@echo [.o] : Deleted !

fclean			:	clean
				rm -f $(NAME)
				@echo [$(NAME)] : Deleted !

re				:	fclean all

.PHONY: 		clean fclean all re

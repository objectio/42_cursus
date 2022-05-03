# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/21 19:04:16 by younjkim          #+#    #+#              #
#    Updated: 2022/04/23 13:39:39 by younjkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

#--------------- DIRS ---------------#

INCLUDE_DIR	= include
SRC_DIR		= src
LIBS_DIR	= libs
OBJS_DIR	= objs

#--------------- FILES ---------------#

LIBS			= $(LIBS_DIR)/Libft/libft.a \

LIBS_HEADERS	= -I $(LIBS_DIR)/Libft/include/ \

INC				= -I $(INCLUDE_DIR) $(LIBS_HEADERS)

SRC				= pa.c \
				  pb.c \
				  error.c \
				  push_swap.c \
				  mid.c \
				  hard.c \
				  easy.c \
				  init.c \
				  ra_rb_rr.c \
				  rra_rrb_rrr.c \
				  sa_sb_ss.c \
				  mid_utils.c \
				  hard_utils.c \
				  hard_utils2.c \

OBJ				= $(addprefix $(OBJS_DIR)/,$(SRC:.c=.o))

#--------------- COMPILATION ---------------#

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g $(INC)

#--------------- RULES ---------------#

objs/%.o:src/%.c
	@mkdir -p $(dir $@)
	@$(CC) -c $(CFLAGS) -o $@ $^
	@echo "Compiling $^"

all:	$(NAME)

$(NAME): $(OBJ) $(LIBS)
	@$(CC) $(OBJ) $(LIBS) -o $(NAME)
	@echo "Built $(NAME)"

$(LIBS_DIR)/Libft/libft.a:
	@make -C $(LIBS_DIR)/Libft

clean:
	@rm -rf $(OBJS_DIR)

fclean:	clean
	@make fclean -C $(LIBS_DIR)/Libft
	@rm -f $(NAME)

re:	fclean all

.PHONY: all re clean fclean

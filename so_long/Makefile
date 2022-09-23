# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/27 21:21:58 by younjkim          #+#    #+#              #
#    Updated: 2022/03/27 21:22:10 by younjkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAMEB = so_long_bonus
GCC = gcc
CFLAGS = -Wall -Werror -Wextra

MINILIBX = ./minilibx_/libmlx.a

SRCS = so_long.c \
		utils/so_long_utils.c \
		read_map_utils.c \
		map_check.c \
		initever.c \
		utils/ft_split.c \
		utils/ft_split_utils.c \
		chmap.c \
		start_game.c \
		hook.c \
		enemy.c \
		move.c \
		events.c \
		utils/ft_itoa.c \
		opendoor.c \

SRCSB = bonus/so_long_bonus.c \
		bonus/so_long_utils_bonus.c \
		bonus/read_map_utils_bonus.c \
		bonus/map_check_bonus.c \
		bonus/initever_bonus.c \
		bonus/ft_split_bonus.c \
		bonus/ft_split_utils_bonus.c \
		bonus/chmap_bonus.c \
		bonus/start_game_bonus.c \
		bonus/hook_bonus.c \
		bonus/move_bonus.c \
		bonus/events_bonus.c \
		bonus/ft_itoa_bonus.c \
		bonus/enemy_bonus.c \
		bonus/opendoor_bonus.c \
		
OBJS = $(SRCS:.c=.o)
OBJSB = $(SRCSB:.c=.o)

all:  $(NAME)

$(NAME): $(OBJS) so_long.h Makefile
	$(GCC) $(CFLAGS) $(OBJS) -lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(NAMEB): $(OBJSB) bonus/so_long_bonus.h Makefile
	$(GCC) $(CFLAGS) $(OBJSB) -lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAMEB)

bonus: $(NAMEB)

clean:
	rm -f $(OBJS) $(OBJSB)
fclean: clean
	rm -f $(NAME) $(NAMEB)

re: fclean all

.PHONY: all clean fclean re bonus

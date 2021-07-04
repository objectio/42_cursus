# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/04 19:42:52 by younjkim          #+#    #+#              #
#    Updated: 2021/07/04 21:55:58 by younjkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=libft.a
SOURCE_FILE=ft_bzero.c ft_memset.c ft_memcpy.c \
			ft_memccpy.c ft_memmove.c ft_memchr.c \
			ft_memcmp.c ft_strlen.c ft_strlcpy.c \
			ft_strlcat.c ft_strchr.c ft_strrchr.c \
			ft_strnstr.c ft_strncmp.c ft_atoi.c \
			ft_isalpha.c ft_isdigit.c ft_isalnum.c \
			ft_isascii.c ft_isprint.c ft_toupper.c \
			ft_tolower.c ft_strdup.c ft_calloc.c \
			ft_substr.c ft_strjoin.c ft_strtrim.c \
			ft_split.c ft_itoa.c ft_strmapi.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
BONUS_FILE=ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
		   ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
		   ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJS=${SOURCE_FILE:.c=.o}
OBJS_B=${BONUS_FILE:.c=.o}
ifdef WITH_BONUS
	OBJ_FILES = $(OBJS) $(OBJS_B)
else
	OBJ_FILES = $(OBJS)
endif
.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
$(NAME):$(OBJ_FILES)
	ar rc $@ $^
bonus:$(OBJS_B)
	make WITH_BONUS=1 all
all:$(NAME)
clean:
	rm -f $(OBJS) $(OBJS_B)
fclean:
	rm -f $(OBJS) $(OBJS_B) $(NAME)
re:fclean all

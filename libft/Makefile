# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/12 18:45:14 by younjkim          #+#    #+#              #
#    Updated: 2021/06/13 05:06:06 by younjkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -c

INCDIR = libft.h

NAME = libft.a
SOURCES = ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_strmapi.c \
		  ft_itoa.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_calloc.c \
		  ft_memset.c ft_putchar_fd.c ft_strchr.c ft_strjoin.c ft_strlcat.c ft_strdup.c \
		  ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
		  ft_calloc.c ft_putendl_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_strrchr.c ft_strnstr.c ft_atoi.c
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@ -I $(INCDIR)

$(NAME): $(OBJECTS)
	ar cr $@ $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/25 19:39:06 by younjkim          #+#    #+#              #
#    Updated: 2022/02/26 16:37:45 by younjkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGC = -Wall -Wextra -Werror
CC = gcc
c_src = minitalk_utils.c minitalk_utils2.c
c_obj=$(c_src:.c=.o)
cb_src = bonus/minitalk_utils_bonus.c bonus/minitalk_utils_bonus2.c
cb_obj=$(cb_src:.c=.o)
server = server
client = client
server_bonus = server_bonus
client_bonus = client_bonus
all: $(server) $(client)

bonus:$(server_bonus) $(client_bonus)

$(server_bonus):$(cb_obj) bonus/minitalk_bonus.h
	$(CC) $(CFLAGS) bonus/server_bonus.c $(cb_obj) -o $(server_bonus)
$(client_bonus):$(cb_obj) bonus/minitalk_bonus.h
	$(CC) $(CFLAGS) bonus/client_bonus.c $(cb_obj) -o $(client_bonus)

$(server):$(c_obj) minitalk.h
	$(CC) $(CFLAGS) server.c $(c_obj) -o $(server)
$(client):$(c_obj) minitalk.h
	$(CC) $(CFLAGS) client.c $(c_obj) -o $(client)
%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -rf $(c_obj) $(cb_obj)
fclean: clean
	rm -rf $(client) $(server) $(client_bonus) $(server_bonus)
re: fclean all

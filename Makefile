# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fel-abbo <fel-abbo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/10 19:00:39 by fel-abbo          #+#    #+#              #
#    Updated: 2024/04/30 10:16:16 by fel-abbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CLIENT = client
SERVER = server


FLAGS = -Wall -Wextra -Werror


HEADERS_DIR = .  

CC = gcc


SRCS_CLIENT = client.c utils.c
SRCS_SERVER = server.c utils.c


OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER = $(SRCS_SERVER:.c=.o)


.c.o:
	$(CC) $(FLAGS) -I$(HEADERS_DIR) -c $< -o $@


all: $(CLIENT) $(SERVER)

$(CLIENT): $(OBJS_CLIENT)
	$(CC) $(FLAGS) -o $(CLIENT) $(OBJS_CLIENT)

$(SERVER): $(OBJS_SERVER)
	$(CC) $(FLAGS) -o $(SERVER) $(OBJS_SERVER)

clean:
	rm -f $(OBJS_CLIENT) $(OBJS_SERVER)

fclean: clean
	rm -f $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fel-abbo <fel-abbo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/10 19:00:39 by fel-abbo          #+#    #+#              #
#    Updated: 2024/04/18 04:25:17 by fel-abbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Noms des exécutables
CLIENT = client
SERVER = server

# Flags de compilation
FLAGS = -Wall -Wextra -Werror

# En-têtes
HEADERS_DIR = .  # Ajuste si tes fichiers d'en-tête sont dans un autre dossier

# Compilateur
CC = gcc

# Sources
SRCS_CLIENT = client.c utils.c
SRCS_SERVER = server.c utils.c

# Objets
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER = $(SRCS_SERVER:.c=.o)

# Règle implicite de compilation
.c.o:
	$(CC) $(FLAGS) -I$(HEADERS_DIR) -c $< -o $@

# Cibles
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

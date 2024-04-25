# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fel-abbo <fel-abbo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/10 19:00:39 by fel-abbo          #+#    #+#              #
#    Updated: 2024/04/25 05:43:32 by fel-abbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Noms des exécutables
CLIENT = client
SERVEUR = serveur

# Flags de compilation
FLAGS = -Wall -Wextra -Werror

# En-têtes
HEADERS_DIR = .  # Ajuste si les fichiers d'en-tête sont dans un autre dossier

# Compilateur
CC = gcc

# Sources
SRCS_CLIENT = client.c utils.c
SRCS_SERVEUR = serveur.c utils.c

# Objets
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVEUR = $(SRCS_SERVEUR:.c=.o)

# Règle implicite de compilation
.c.o:
	$(CC) $(FLAGS) -I$(HEADERS_DIR) -c $< -o $@

# Cibles
all: $(CLIENT) $(SERVEUR)

$(CLIENT): $(OBJS_CLIENT)
	$(CC) $(FLAGS) -o $(CLIENT) $(OBJS_CLIENT)

$(SERVEUR): $(OBJS_SERVEUR)
	$(CC) $(FLAGS) -o $(SERVEUR) $(OBJS_SERVEUR)

clean:
	rm -f $(OBJS_CLIENT) $(OBJS_SERVEUR)

fclean: clean
	rm -f $(CLIENT) $(SERVEUR)

re: fclean all

.PHONY: all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: diavolo <diavolo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/03 02:47:34 by diavolo           #+#    #+#              #
#    Updated: 2024/04/07 15:08:28 by diavolo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     = ircserv
CC         = c++
CFLAGS     = -Wall -Wextra -Werror -g3 -std=c++98
SRCS     =  main.cpp
OBJ_DIR = obj
INCLUDES_FOLDER = includes/
SRC_FOLDER = src/

HEADERS       = $(wildcard $(INCLUDES_FOLDER)*.hpp)

OBJS    = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_FOLDER)%.cpp $(HEADERS) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:			all clean fclean re

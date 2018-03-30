# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/28 20:11:50 by mtan              #+#    #+#              #
#    Updated: 2018/03/29 23:27:00 by ikozlov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

# compiler
CC = gcc
FLAGS = -Wall -Wextra -Werror
DEBUG = -g
FLAGS += $(DEBUG)

# directories
OBJ_DIR = obj/
SRC_DIR = src/
INC_DIR = includes/
LIBFT_DIR = libft/

# files
# SRC_FILES = ft_printf.c
SRC_FILES = $(notdir $(wildcard $(SRC_DIR)*.c))
OBJ_FILES = $(SRC_FILES:%.c=%.o)

# full path
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
LIBFT = $(LIBFT_DIR)libft.a
INCLUDES = -I $(LIBFT_DIR)includes -I includes/

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT)
	@echo "[INFO] Lem-in executable created"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC_DIR)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "[INFO] Objects removed."

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm $(NAME)
	@echo "[INFO] Lem-in executable deleted"

re: fclean all

.PHONY: all $(NAME) clean fclean re

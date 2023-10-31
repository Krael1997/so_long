# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelrodr <abelrodr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/02 17:40:23 by abelrodr          #+#    #+#              #
#    Updated: 2023/10/31 15:30:52 by abelrodr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
UNAME = $(shell uname)
CFLAGS = -Wall -Wextra -Werror
LFLAGS = $(LIBMLX_DIR)/libmlx42.a

# Additional flags for macOS
ifeq ($(UNAME), Darwin)
    LFLAGS += -L "/Users/$(USER)/.brew/opt/glfw/lib/" -lglfw -framework Cocoa -framework OpenGL -framework IOKit
else ifeq ($(UNAME), Linux)
    LFLAGS += -ldl -lglfw -pthread -lm
else
    @echo "$(R)[The program is only available for Linux and MacOS]\n$(END)"
endif

INC = -I $(INC_DIR) -I $(LIBFT_DIR)/inc -I $(LIBMLX_DIR)/include/MLX42
LIBS = $(LIBFT_DIR)/libft.a $(LIBMLX_DIR)/libmlx42.a
RM = rm -rf

SRCS = $(SRC_DIR)/main.c \
		$(SRC_DIR)/render_map.c \
		$(SRC_DIR)/key_hook.c \
		$(SRC_DIR)/flood_fill.c \
		$(SRC_DIR)/count_characters.c \
		$(SRC_DIR)/check_map.c \
		$(SRC_DIR)/cleaning.c
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

OBJ_DIR = obj
SRC_DIR = src
INC_DIR = inc
LIBFT_DIR = libs/libft
LIBMLX_DIR = libs/MLX42

all: $(NAME)

show:
		@printf "UNAME : $(UNAME)\n"
		@printf "NAME : $(NAME)\n"
		@printf "CC : $(CC)\n"
		@printf "CFLAGS : $(CFLAGS)\n"
		@printf "LFLAGS : $(LFLAGS)\n"
		@printf "SRCS   : $(addprefix \n\t, $(notdir $(SRCS)))\n"$

clean:
		@$(RM) $(OBJ_DIR)
		@make clean -sC $(LIBFT_DIR)
		@make clean -sC $(LIBMLX_DIR)
		@echo "$(G)[Cleaned $(C) '$(NAME) objects' $(G)successfully]\n$(END)"
    
fclean: clean
		@make fclean -sC $(LIBFT_DIR)
		@make fclean -sC $(LIBMLX_DIR)
		@$(RM) so_long
		@echo "$(G)[Removed $(C) '$(NAME)' $(G)successfully]\n$(END)"

re: fclean all

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/so_long.h
		@mkdir -p $(OBJ_DIR)
		@$(CC) $(CFLAGS) $(INC) -c $< -o $@
		@echo "$(G)[Compiled $(C) '$<' $(G)successfully]\n$(END)"

$(NAME): $(OBJS)
		@make -sC $(LIBFT_DIR)
		@make -sC $(LIBMLX_DIR)
		@$(CC) $(CFLAGS) $(OBJS) $(INC) $(LIBS) $(LFLAGS) -o $(NAME)
		@echo "\n$(G)[Compiled $(C) '$(NAME)' $(G)successfully]\n$(END)"

.PHONY: all clean fclean re show

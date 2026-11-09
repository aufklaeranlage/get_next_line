# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abronner <abronner@students.42berlin.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/06 09:59:55 by abronner          #+#    #+#              #
#    Updated: 2025/03/12 18:50:12 by abronner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	libgnl.a

# **************************************************************************** #

SRC_DIR		:=	srcs/

OBJ_DIR		:=	objs/

INC_DIR		:=	includes/

# **************************************************************************** #

SRCS		:=	get_next_line.c get_next_line_utils.c

OBJS		:=	$(patsubst %.c,$(OBJ_DIR)%.o,$(SRCS))

# **************************************************************************** #

CC			:=	cc

CFLAGS		:=	-Wall -Wextra -Werror $(ADDCCFLAGS)

CPPFLAGS	:=	-I$(INC_DIR)

LIBFLAGS	:=

RM			:= rm -rf

# **************************************************************************** #

all: $(NAME)

bonus: all

$(NAME): $(OBJ_DIR) $(OBJS)
	ar rcs -o $(NAME) $(OBJS)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c 
	$(CC) $(CFLAGS) $< $(CPPFLAGS) -c -o $@

re: fclean all

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

.PHONY: all bonus re clean fclean make

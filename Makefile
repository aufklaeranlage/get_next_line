# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abronner <abronner@42studnets.berlin>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/21 09:11:46 by abronner          #+#    #+#              #
#    Updated: 2025/02/21 13:56:32 by abronner         ###   ########.fr        #
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

CFLAGS		:=	-Wall -Wextra -Werror $G

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

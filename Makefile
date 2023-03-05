# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/01 11:33:42 by gylim             #+#    #+#              #
#    Updated: 2023/03/05 19:25:51 by gylim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = srcs
SRC_FILES_MAND = main.c
SRCS_MAND = $(addprefix $(SRC_DIR)/, $(SRC_FILES_MAND))
SRCS_BONUS = $(addprefix $(SRC_DIR)/, $(SRC_FILES_BONUS))
ifdef BONUS_FLAG
	SRCS = $(SRCS_BONUS)
else
	SRCS = $(SRCS_MAND)
endif

OBJ_DIR = objs
OBJ_FILES_MAND = $(SRC_FILES_MAND:.c=.o)
OBJS_MAND = $(addprefix $(OBJ_DIR)/, $(OBJ_FILES_MAND))
OBJS_BONUS = 
ifdef BONUS_FLAG
	OBJS = $(OBJS_BONUS)
else
	OBJS = $(OBJS_MAND)
endif

#INC_DIR = include
#INC_FILES_MAND = libft.h
#ifdef BONUS_FLAG
#	INC = $(addprefix $(INC_DIR)/, $(INC_FILES_BONUS))
#else
#	INC =  $(addprefix $(INC_DIR)/, $(INC_FILES_MAND))
#endif

LIB_DIR = libft
LIBS = -lft

all: $(NAME)

bonus:
	make BONUS_FLAG=1 all

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJS): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(NAME): $(OBJS)
	make -C $(LIB_DIR) all
	$(CC) $(CFLAGS) -L $(LIB_DIR) $(LIBS) -o $@ $^

clean:
	make -C $(LIB_DIR) clean
	rm -rf $(OBJ_DIR)

fclean:
	make clean
	make -C $(LIB_DIR) fclean
	rm -f $(NAME)

re: 
	make fclean
	make all

.PHONY: clean fclean re all bonus

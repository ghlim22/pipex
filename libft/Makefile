# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 15:22:26 by gylim             #+#    #+#              #
#    Updated: 2023/03/05 14:38:29 by gylim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs

SRC_DIR = srcs
SRC_FILES = ft_isalnum.c \
	   		ft_isalpha.c \
	   		ft_isascii.c \
	   		ft_isdigit.c \
	  		ft_isprint.c \
	   		ft_tolower.c \
	   		ft_toupper.c \
	   		ft_bzero.c \
	   		ft_calloc.c \
	   		ft_memchr.c \
	   		ft_memcmp.c \
	   		ft_memcpy.c \
	   		ft_memmove.c \
	   		ft_memset.c \
	   		ft_strchr.c \
	   		ft_strdup.c \
	   		ft_strlcat.c \
	   		ft_strlcpy.c \
	   		ft_strlen.c \
	   		ft_strncmp.c \
	   		ft_strnstr.c \
	   		ft_strrchr.c \
	   		ft_atoi.c \
	   		ft_substr.c \
	   		ft_strjoin.c \
	   		ft_strtrim.c \
	   		ft_split.c \
	   		ft_itoa.c \
	   		ft_strmapi.c \
	   		ft_striteri.c \
	   		ft_putchar_fd.c \
	   		ft_putstr_fd.c \
	   		ft_putendl_fd.c \
	   		ft_putnbr_fd.c \
			ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_printf.c \
			ft_write.c \
			print_addr.c \
			print_char.c \
			print_hex.c \
			print_nbr.c \
			print_str.c \
			print_uint.c \
			get_next_line.c \
			get_next_line_utils.c
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ_DIR = objs
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJS = $(addprefix $(OBJ_DIR)/, $(OBJ_FILES))

INC_DIR = include
INC_FILES = libft.h
INC = $(addprefix $(INC_DIR)/, $(INC_FILES))

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC)
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(OBJS): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(NAME): $(OBJS)
	@echo "==============="
	@echo "compiling $@"
	@echo "==============="
	$(AR) $(ARFLAGS) $@ $^

clean: 
	rm -rf $(OBJ_DIR)

fclean:
	make clean
	rm -f $(NAME)

re:
	make fclean
	make all

.PHONY: clean fclean re all bonus
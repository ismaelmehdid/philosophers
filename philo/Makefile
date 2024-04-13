# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 15:07:05 by ismaelmehdi       #+#    #+#              #
#    Updated: 2024/04/03 04:37:21 by imehdid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = ${wildcard srcs/*.c srcs/errors_handling/*.c srcs/init_data/*.c srcs/utils/*.c srcs/dinner/*.c}

OBJDIR = ./objs
OBJS = ${SRCS:%.c=$(OBJDIR)/%.o}

CC = cc -g -pthread
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

all: ${NAME}

$(OBJDIR)/%.o: %.c
		@mkdir -p $(@D)
		@${CC} ${CFLAGS} -c $< -o $@

$(NAME): ${OBJS}
		@${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
		@${RM} ${OBJS}

fclean: clean
		@${RM} ${OBJS} ${NAME} ${OBJDIR}

re: fclean all

.PHONY: all clean fclean re
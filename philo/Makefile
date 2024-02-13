# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 15:07:05 by ismaelmehdi       #+#    #+#              #
#    Updated: 2024/02/13 20:01:00 by imehdid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = ${wildcard errors_handling/*.c ./*.c}

OBJS = ${SRCS:.c=.o}

CC = cc
CFLAGS = -g -Wall -Wextra -Werror

RM = rm -rf

all: ${NAME}

${NAME}: ${OBJS}
		 @${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
		@${RM} ${OBJS}

fclean: clean
		@${RM} ${NAME} ${OBJS} ${NAME_BONUS}

re: fclean all

.PHONY: all clean fclean re
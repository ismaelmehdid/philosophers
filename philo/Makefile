# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imehdid <imehdid@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 15:07:05 by ismaelmehdi       #+#    #+#              #
#    Updated: 2024/05/02 14:26:09 by imehdid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = srcs/dinner/dinner.c \
		srcs/dinner/dinner_utils.c \
		srcs/dinner/eat.c \
		srcs/dinner/monitor.c \
		srcs/dinner/sleep.c \
		srcs/dinner/think.c \
		srcs/dinner/threads_manager.c \
		srcs/errors_handling/errors_handling.c \
		srcs/init_data/init_data_utils.c \
		srcs/init_data/init_data.c \
		srcs/utils/getters_and_setters/getters.c \
		srcs/utils/getters_and_setters/setters.c \
		srcs/utils/free_and_destroy.c \
		srcs/utils/philosophers_utils.c \
		srcs/philosophers.c

OBJDIR = ./objs
OBJS = ${SRCS:%.c=$(OBJDIR)/%.o}

CC = cc -pthread
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
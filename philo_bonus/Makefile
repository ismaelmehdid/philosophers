# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 15:07:05 by ismaelmehdi       #+#    #+#              #
#    Updated: 2024/04/29 19:52:27 by imehdid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_BONUS = philo_bonus

SRCS = srcs_bonus/philosophers_bonus.c \
		srcs_bonus/dinner_bonus/dinner_bonus.c \
		srcs_bonus/dinner_bonus/dinner_utils_bonus.c \
		srcs_bonus/dinner_bonus/eat_bonus.c \
		srcs_bonus/dinner_bonus/monitor_bonus.c \
		srcs_bonus/dinner_bonus/sleep_bonus.c \
		srcs_bonus/dinner_bonus/think_bonus.c \
		srcs_bonus/errors_handling_bonus/errors_handling_bonus.c \
		srcs_bonus/init_data_bonus/init_data_bonus.c \
		srcs_bonus/init_data_bonus/init_data_utils_bonus.c \
		srcs_bonus/utils_bonus/getters_and_setters_bonus/getters_bonus.c \
		srcs_bonus/utils_bonus/getters_and_setters_bonus/setters_bonus.c \
		srcs_bonus/utils_bonus/free_and_destroy_bonus.c \
		srcs_bonus/utils_bonus/philosophers_utils_bonus.c \

OBJDIR = ./objs_bonus
OBJS = ${SRCS:%.c=$(OBJDIR)/%.o}

CC = cc -pthread
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

all: ${NAME_BONUS}

$(OBJDIR)/%.o: %.c
		@mkdir -p $(@D)
		@${CC} ${CFLAGS} -c $< -o $@

$(NAME_BONUS): ${OBJS}
		@${CC} ${CFLAGS} ${OBJS} -o ${NAME_BONUS}

clean:
		@${RM} ${OBJS}

fclean: clean
		@${RM} ${OBJS} ${NAME_BONUS} ${OBJDIR}

re: fclean all

bonus: ${NAME_BONUS}

.PHONY: all clean fclean re bonus
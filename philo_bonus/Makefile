# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 15:07:05 by ismaelmehdi       #+#    #+#              #
#    Updated: 2024/04/19 17:15:52 by imehdid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_BONUS = philo_bonus

SRCS = ${wildcard srcs_bonus/*.c srcs_bonus/errors_handling_bonus/*.c srcs_bonus/init_data_bonus/*.c srcs_bonus/utils_bonus/*.c srcs_bonus/dinner_bonus/*.c srcs_bonus/utils_bonus/getters_and_setters_bonus/*.c}

OBJDIR = ./objs_bonus
OBJS = ${SRCS:%.c=$(OBJDIR)/%.o}

CC = cc -g -pthread
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
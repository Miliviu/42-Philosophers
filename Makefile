# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhagon <juhagon@student.42madrid.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 09:38:55 by juhagon           #+#    #+#              #
#    Updated: 2022/01/24 12:58:17 by juhagon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = philo.c utils/utils.c
OBJS = ${SRCS:.c=.o}
GCC   = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = philo
RM = rm -f

.c.o:
	${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	${GCC} $(OBJS) -g -pthread -o ${NAME}

all:	${NAME}
clean:
	${RM} ${OBJS}

fclean:		clean
	${RM} ${NAME}

re: fclean all

.PHONY:		all clean fclean re

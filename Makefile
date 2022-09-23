# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhagon <juhagon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 09:38:55 by juhagon           #+#    #+#              #
#    Updated: 2022/09/20 12:20:53 by juhagon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = philo.c utils/utils.c thread.c
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

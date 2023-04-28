# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ride-sou <ride-sou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/13 10:05:12 by ride-sou          #+#    #+#              #
#    Updated: 2023/04/28 13:40:32 by ride-sou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c ft_printf_aux.c ft_print_ptr.c ft_print_unsigned.c

SRC += ft_print_hex.c

MAKE = make -c
LIB_PATH = libft/libft.a

OBJS = ${SRC:.c=.o}

RM = rm -f
CFLAGS = -Wall -Wextra -Werror

.c.o:
		cc ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):        ${MAKE} ${LIB_PATH}
				cp ${LIB_PATH} ${NAME}
				ar rcs ${NAME} ${OBJS}

all:    ${NAME}

clean:	${MAKE} ${LIB_PATH} clean
		${RM} ${OBJS}

fclean: clean
		${MAKE} ${LIB_PATH} fclean
		${RM} ${NAME}

re:     fclean all

.PHONY: all bonus clean fclean re
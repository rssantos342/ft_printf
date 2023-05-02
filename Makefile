# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ride-sou <ride-sou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/13 10:05:12 by ride-sou          #+#    #+#              #
#    Updated: 2023/05/02 10:45:42 by ride-sou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c ft_printf_aux.c ft_print_hex_ptr.c ft_print_unsigned.c

OBJS = ${SRC:.c=.o}

RM = rm -f
CFLAGS = -Wall -Wextra -Werror
MAKE = make -C
LIB_PATH = libft/libft.a

all:    ${NAME}

.c.o:
		cc ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):    ${OBJS}
			${MAKE} libft
			cp ${LIB_PATH} ${NAME}
			ar rcs ${NAME} ${OBJS}

clean:	
		${MAKE} libft clean
		${RM} ${OBJS}

fclean:	clean
		${MAKE} libft fclean
		${RM} ${NAME}

re:     fclean all

.PHONY: all clean fclean re
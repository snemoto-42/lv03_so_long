# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 08:54:15 by snemoto           #+#    #+#              #
#    Updated: 2023/03/19 15:30:40 by snemoto          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PRINTF_SRCS	= \
		ft_printf.c \
		ft_put_d.c \
		ft_put_s.c \
		ft_put_x.c \
		ft_put_p.c

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f
NAME	= libftprintf.a
OBJS	= ${PRINTF_SRCS:.c=.o}
LIBFT_PATH = ../libft

$(NAME): ${OBJS}
		cd "$(PWD)/${LIBFT_PATH}" && make bonus
		cp ${LIBFT_PATH}/libft.a $(NAME)
		ar rcs ${NAME} ${OBJS}

all:	${NAME}

clean:
		${RM} ${OBJS}
		cd "$(PWD)/${LIBFT_PATH}" && make fclean

fclean:	clean
		${RM} ${NAME}

re:		fclean all

bonus:	all

.PHONY: all clean fclean re bonus

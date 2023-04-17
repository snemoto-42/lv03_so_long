# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/28 15:41:54 by snemoto           #+#    #+#              #
#    Updated: 2023/04/16 22:44:00 by snemoto          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOLONG_SRCS	= \
			sl_init.c \
			sl_map.c \
			sl_map_check.c \
			sl_img.c \
			sl_hook.c \
			main.c

CC		= cc
RM		= rm -f
NAME	= so_long

SRCS	= ${SOLONG_SRCS}
OBJS	= ${SOLONG_SRCS:.c=.o}

LIBFT_PATH = libft
LIBFT_INCLUDE = libft.a
LIBFTPRINTF_PATH = libftprintf
LIBFTPRINTF_INCLUDE = libftprintf.a

CFLAGS	= -Wall -Wextra -Werror -I include -I/usr/X11/include
MLX_PATH = minilibx-linux
MLX_INCLUDE = libmlx_Darwin.a

X11_PATH = -L/usr/X11/include/../lib
X11_INCLUDE = -lX11 -lXext

$(NAME): ${OBJS}
		cd "$(PWD)/${LIBFT_PATH}" && make bonus
		cd "$(PWD)/${LIBFTPRINTF_PATH}" && make bonus
		cd "$(PWD)/${MLX_PATH}" && make
		${CC} \
		${CFLAGS} \
			${X11_PATH} ${X11_INCLUDE} \
			$(PWD)/${LIBFT_PATH}/${LIBFT_INCLUDE} \
			$(PWD)/${LIBFTPRINTF_PATH}/${LIBFTPRINTF_INCLUDE} \
			$(PWD)/${MLX_PATH}/${MLX_INCLUDE} \
			${SRCS} -o ${NAME}

all:	${NAME}

clean:
		${RM} ${OBJS}
		cd "$(PWD)/${LIBFT_PATH}" && make fclean
		cd "$(PWD)/${LIBFTPRINTF_PATH}" && make fclean
		cd "$(PWD)/${MLX_PATH}" && make clean

fclean:	clean
		${RM} ${NAME}

re:		fclean all

bonus:	all

.PHONY: all clean fclean re bonus

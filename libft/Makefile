# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 20:37:17 by snemoto           #+#    #+#              #
#    Updated: 2023/03/21 16:47:41 by snemoto          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PART1_SRCS = \
		ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strnstr.c \
		ft_strdup.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_tolower.c \
		ft_toupper.c

PART2_SRCS = \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_itoa.c \
		ft_split.c \
		ft_strmapi.c \
		ft_striteri.c

PART_BONUS_SRCS = \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f
NAME	= libft.a
SRCS	= ${PART1_SRCS} ${PART2_SRCS} 
OBJS	= ${SRCS:.c=.o}
BONUS_SRCS	= ${PART_BONUS_SRCS}
BONUS_OBJS	= ${BONUS_SRCS:.c=.o}

ifdef WITH_BONUS
	OBJS += $(BONUS_OBJS)
endif

$(NAME): ${OBJS}
		ar rcs ${NAME} ${OBJS}

all:	@${NAME}

bonus:
		@make WITH_BONUS=1

clean:
		@${RM} ${OBJS}
		@${RM} ${BONUS_OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re bonus

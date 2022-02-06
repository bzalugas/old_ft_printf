#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/15 16:01:33 by bzalugas          #+#    #+#              #
#    Updated: 2022/02/06 10:50:41 by bzalugas         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRCS	=	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c \
			ft_memcmp.c ft_strlen.c ft_islower.c ft_isupper.c ft_isalpha.c ft_isdigit.c \
			ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strchr.c \
			ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_atoi.c \
			ft_calloc.c ft_strdup.c ft_substr_free.c ft_strjoin_free.c ft_strtrim.c ft_split.c \
			ft_putchar.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
			ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_utoa.c \
			ft_base_convert.c ft_find_char.c ft_lstdelcontent.c ft_get_pow.c ft_abs.c

OBJS 	= 	$(SRCS:.c=.o)

NAME	= 	libft.a

CC		= 	cc

CFLAGS	= 	-Wall -Wextra -Werror

AR		= 	ar rc

RM		= 	rm -f

all:		$(NAME)

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)

%.o:		%.c
			$(CC) $(CFLAGS) -o $(<:.c=.o) -c $<

clean:
			$(RM) $(OBJS) $(OBJM)

fclean:		clean
			$(RM) $(NAME) $(TNAME)

re:			fclean all

.PHONY:		all clean fclean re

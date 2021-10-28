#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/15 16:01:33 by bzalugas          #+#    #+#              #
#    Updated: 2021/10/26 15:21:11 by bzalugas         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRCS	=	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c \
			ft_memcmp.c ft_strlen.c ft_islower.c ft_isupper.c ft_isalpha.c ft_isdigit.c \
			ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strchr.c \
			ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_atoi.c \
			ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
			ft_putchar.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
			ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

MAIN	=	main.c

OBJM	=	$(MAIN:.c=.o)

TNAME	= 	test

OBJS 	= 	$(SRCS:.c=.o)

NAME	= 	libft.a

CC		= 	clang

CFLAGS	= 	-Wall -Wextra -Werror

AR		= 	ar rc

RM		= 	rm -f

GREEN	=	"\033[1;32m"

RED		=	"\033[1;31m"

END		=	"\033[0m"

CLEAN	=	@echo $(RED)"Cleaning objects of $(NAME)"$(END)

BUILT	=	@echo $(GREEN)"Built $(NAME)"$(END)

DELETE	=	@echo $(RED)"Cleaning $(NAME)"$(END)

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(AR) $(NAME) $(OBJS)
			$(BUILT)

%.o:		%.c
			@$(CC) $(CFLAGS) -o $(<:.c=.o) -c $<

test:		$(NAME)
			@$(CC) $(CFLAGS) -o $(TNAME) $(MAIN) -L. -lft

clean:
			@$(RM) $(OBJS) $(OBJM)
			$(CLEAN)

fclean:		clean
			@$(RM) $(NAME) $(TNAME)
			$(DELETE)

re:			fclean all

.PHONY:		all clean fclean re test

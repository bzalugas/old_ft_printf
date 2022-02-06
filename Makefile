#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/26 13:43:55 by bzalugas          #+#    #+#              #
#    Updated: 2022/02/06 13:25:19 by bzalugas         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

##### Sources ######

SRC			=	ft_printf.c buffer_char.c buffer.c buffer_add.c\
				char_handlers.c num_handlers.c flags.c format_flags.c

OBJS		=	$(addprefix $(DIR_OUT)/,$(SRC:.c=.o))

DIR_SRCS	=	src

DIR_OUT		=	obj

DIR_LIBFT	=	libft

HEADERS		=	includes

##### Name of the program #####

NAME		=	libftprintf.a

LIBFT_NAME	=	libft.a

LIBFT		=	$(DIR_LIBFT)/$(LIBFT_NAME)

##### Commands #####

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror

LIB			=	ar rc

RM			=	rm -f

##### RULES #####

all:				$(NAME)

bonus:				$(NAME)

$(NAME):			$(OBJS)
					make -C $(DIR_LIBFT) all
					cp $(LIBFT) ./$(NAME)
					$(LIB) $(NAME) $(OBJS)

$(DIR_OUT)/%.o:		$(DIR_SRCS)/%.c | $(DIR_OUT)
					$(CC) $(CFLAGS) -I $(HEADERS) -o $@ -c $<

$(DIR_OUT):
					mkdir -p $(DIR_OUT)

clean:				
					rm -rf $(DIR_OUT)

fclean:				clean
					make -C $(DIR_LIBFT) fclean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re libft bonus

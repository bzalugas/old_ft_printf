#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/26 13:43:55 by bzalugas          #+#    #+#              #
#    Updated: 2021/10/28 10:31:01 by bzalugas         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	libftprintf.a

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror

AR			=	ar rc

DIR_SRCS	=	src

DIR_OUT		=	bin

SRCS		=	ft_printf.c

OBJS		=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)

libft:

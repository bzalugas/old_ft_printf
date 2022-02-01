#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/26 13:43:55 by bzalugas          #+#    #+#              #
#    Updated: 2022/02/01 19:59:24 by bzalugas         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

##### Sources ######

SRC			=	ft_printf.c buffer_char.c buffer.c buffer_add.c char_handlers.c\
				num_handlers.c format_flags.c

SRCS		=	$(addprefix $(DIR_SRCS)/,$(SRC))

OBJS		=	$(addprefix $(DIR_OUT)/,$(SRC:.c=.o))

BONUS_SRC	=	ft_printf_bonus.c buffer_char.c buffer.c buffer_add.c\
				char_handlers_bonus.c num_handlers_bonus.c flags.c format_flags.c

BONUS_SRCS	=	$(addprefix $(DIR_SRCS)/,$(BONUS_SRC))

BONUS_OBJS	=	$(addprefix $(DIR_OUT)/,$(BONUS_SRC:.c=.o))

DIR_SRCS	=	src

DIR_OUT		=	obj

DIR_LIBFT	=	libft

HEADERS		=	includes

##### Name of the program #####

NAME		=	libftprintf.a

LIBFT_NAME	=	libft.a

LIBFT		=	$(DIR_LIBFT)/$(LIBFT_NAME)

TESTER_NAME	=	tester.out

##### Commands #####

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror

PRINTF_FLAG	=	-L. -lftprintf

LIB			=	ar rc

RM			=	rm -f

RMDIR		=	rmdir

##### Colors for the shell #####

GREEN		=	\033[1;32m

RED			=	\033[1;31m

END			=	\033[0m

##### RULES #####

all:				$(NAME)

$(NAME):			$(OBJS)
					make -C $(DIR_LIBFT) all
					@cp $(LIBFT) ./$(NAME)
					@echo "$(GREEN)$(LIBFT_NAME) copied in current folder$(END)"
					@$(LIB) $(NAME) $(OBJS)
					@echo "$(GREEN)$(NAME) built$(END)"

bonus:				fclean $(BONUS_OBJS)
					@$(LIB) $(NAME) $(BONUS_OBJS)
					@echo "$(GREEN)$(NAME) bonuses built$(END)"

#Rule for every sources of the project

$(DIR_OUT)/%.o:		$(DIR_SRCS)/%.c | $(DIR_OUT)
					@$(CC) $(CFLAGS) -I $(HEADERS) -o $@ -c $<
					@echo "$(GREEN)$< compiled$(END)"

$(DIR_OUT):
					@mkdir -p $@
					@echo "$(GREEN)$(DIR_OUT) folder created$(END)"
clean:
					@$(RM) $(OBJS) $(BONUS_OBJS)
					@$(RMDIR) $(DIR_OUT)
					@echo "$(GREEN)Objects and objects folder deleted$(END)"

fclean:				clean
					@make -C $(DIR_LIBFT) fclean
					@echo "$(GREEN)fclean libft$(END)"
					@$(RM) $(NAME)
					@$(RM) $(TESTER_NAME)
					@echo "$(GREEN)$(NAME) deleted$(END)"
					@echo "$(GREEN)$(TESTER_NAME) deleted$(END)"

re:					fclean all

.PHONY:				libft bonus

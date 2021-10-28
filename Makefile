#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/26 13:43:55 by bzalugas          #+#    #+#              #
#    Updated: 2021/10/28 20:09:47 by bzalugas         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

##### Sources ######

SRC			=	ft_printf.c

SRCS		=	$(addprefix $(DIR_SRCS)/,$(SRC))

OBJS		=	$(addprefix $(DIR_OUT)/,$(SRC:.c=.o))

DIR_SRCS	=	src

DIR_OUT		=	obj

DIR_LIBFT	=	libft

S_TESTER	=	tester.c

O_TESTER	=	$(S_TESTER:.c=.out)

##### Name of the program #####

NAME		=	libftprintf.a

LIBFT_NAME	=	libft.a

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

##### Variable to know if DIR_OUT exists #####

OUT			=	$(shell if [ -d $(DIR_OUT) ]; then echo "true";fi;)

##### RULES #####

all:				$(NAME)

$(NAME):			$(OBJS)
					@$(LIB) $(NAME) $(OBJS)
					@echo "$(GREEN)$(NAME) built$(END)"

test:				$(NAME) $(O_TESTER)
					@echo
					./$(TESTER_NAME)

libft:
					@make -C $(DIR_LIBFT) all
					@cp $(DIR_LIBFT)/$(LIBFT_NAME) ./$(NAME)
					@echo "$(GREEN)$(LIBFT_NAME) copied in current folder$(END)"

#Rule for every sources of the project

$(DIR_OUT)/%.o:		$(DIR_SRCS)/%.c libft
					@mkdir -p $(DIR_OUT)
					@echo "$(GREEN)$(DIR_OUT) folder created$(END)"
					@$(CC) $(CFLAGS) -o $@ -c $<
					@echo "$(GREEN)All sources compiled$(END)"

#Rule for the tester
tester.out:			tester.c
					@$(CC) $(CFLAGS) -o $(TESTER_NAME) $(PRINTF_FLAG)
					@echo "$(GREEN)Tester compiled$(END)"

ifeq ($(OUT),true)
clean:
					@$(RM) $(OBJS)
					@$(RMDIR) $(DIR_OUT)
					@echo "$(GREEN)Objects and objects folder deleted$(END)"
else
clean:
					@echo "$(RED)Folder $(DIR_OUT) doesn't exists$(END)"
endif

fclean:				clean
					@$(RM) $(NAME)
					@$(RM) $(LIBFT_NAME)
					@$(RM) $(O_TESTER)
					@echo "$(GREEN)$(NAME) deleted$(END)"
					@echo "$(GREEN)$(LIBFT_NAME) deleted$(END)"
					@echo "$(GREEN)$(O_TESTER) deleted$(END)"

re:					fclean all

.PHONY:				libft

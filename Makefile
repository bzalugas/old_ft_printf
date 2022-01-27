#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/26 13:43:55 by bzalugas          #+#    #+#              #
#    Updated: 2022/01/27 12:28:23 by bzalugas         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

##### Sources ######

SRC			=	ft_printf.c buffer_char.c buffer.c buffer_add.c flags_init.c \
				char_handlers.c num_handlers.c

SRCS		=	$(addprefix $(DIR_SRCS)/,$(SRC))

OBJS		=	$(addprefix $(DIR_OUT)/,$(SRC:.c=.o))

DIR_SRCS	=	src

DIR_OUT		=	obj

DIR_LIBFT	=	libft

# S_TESTER	=	tester.c

# O_TESTER	=	$(S_TESTER:.c=.out)

DIR_TESTS	=	tests

SRC_TESTS	=	CuTest.c AllTests.c ft_printfTest.c bufferTests.c intermediaryTests.c\
				charTests.c stringTests.c pointerTests.c hexaTests.c decimalTests.c\
				intTests.c unsignedTests.c

SRCS_TESTS	=	$(addprefix $(DIR_TESTS)/,$(SRC_TESTS))

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

# test:				$(NAME) $(O_TESTER)
# 					@echo
# 					./$(TESTER_NAME)

test:				$(NAME) $(TESTER_NAME)
					@echo
					./$(TESTER_NAME)

libft:
					@make -C $(DIR_LIBFT) all
					@cp $(DIR_LIBFT)/$(LIBFT_NAME) ./$(NAME)
					@echo "$(GREEN)$(LIBFT_NAME) copied in current folder$(END)"

#Rule for every sources of the project

$(DIR_OUT)/%.o:		$(DIR_SRCS)/%.c libft createDirOut
					@$(CC) $(CFLAGS) -o $@ -c $<
					@echo "$(GREEN)$< compiled$(END)"

createDirOut:
					@mkdir -p $(DIR_OUT)
					@echo "$(GREEN)$(DIR_OUT) folder created$(END)"

#Rule for the tester
# $(TESTER_NAME):		tester.c
# 					@$(CC) $(CFLAGS) -o $(TESTER_NAME) tester.c $(PRINTF_FLAG)
# 					@echo "$(GREEN)Tester compiled$(END)"

#Rule for the tests
$(TESTER_NAME):		$(SRCS_TESTS)
					@$(CC) -o $(TESTER_NAME) $(SRCS_TESTS) $(CFLAGS) $(PRINTF_FLAG)

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
					@make -C $(DIR_LIBFT) fclean
					@echo "$(GREEN)fclean libft$(END)"
					@$(RM) $(NAME)
					@$(RM) $(TESTER_NAME)
					@echo "$(GREEN)$(NAME) deleted$(END)"
					@echo "$(GREEN)$(TESTER_NAME) deleted$(END)"

re:					fclean all

.PHONY:				libft

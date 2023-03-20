# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 13:51:13 by ivan-mel          #+#    #+#              #
#    Updated: 2023/03/20 14:40:46 by ivan-mel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		:= 	push_swap
LIBS		:=	./libft/libft.a
HEADER		:=	-I libft
HEADERS		:=	libft/libft.h
#UTILS
RM 			:=	rm -rf
FLAGS 		:=	-Wall -Werror -Wextra -g
SRC			:=	parser.c \
				main.c \
				list.c \
				push.c \
				rotate.c \
				swap.c \
				operations_push_swap.c \
				operations_rotate.c \
				operations_rev_rotate.c \
				bubblesort.c \
				bubblesort_utils.c \
				sorting_a.c \
				sorting_b.c \
				quicksort.c \
				few_numbers.c \
				error.c \
#BONUS
SRCB		:=	parser_bonus.c \
				checker_bonus.c \
				list_bonus.c \
				push_bonus.c \
				rotate_bonus.c \
				swap_bonus.c \
				operations_push_swap_bonus.c \
				operations_rotate_bonus.c \
				operations_rev_rotate_bonus.c \
				bubblesort_bonus.c \
				bubblesort_utils_bonus.c \
				error_bonus.c 

#OBJB_FILES	=	${SRCB:.c=.o}
OBJ_DIR		:=	./obj
SRC_DIR 	:= 	./src
# Reset
Color_Off	=	"\033[0m"			# Text Reset
# Regular Colors
Black		=	"\033[0;30m"		# Black
Red			=	"\033[0;31m"		# Red
Green		=	"\033[0;32m"		# Green
Yellow		=	"\033[0;33m"		# Yellow
Blue		=	"\033[0;34m"		# Blue
Purple		=	"\033[0;35m"		# Purple
Cyan		=	"\033[0;36m"		# Cyan
White		=	"\033[0;37m"		# White
# Avoid relinking in bonus
ifdef WITH_BONUS
	NAME	:=	checker
	OBJ		:=	$(addprefix $(OBJ_DIR)/,$(SRCB:.c=.o))
else
	OBJ		:=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
endif
# Add obj directory to obj path
SRC		:=	$(addprefix $(SRC_DIR)/,$(SRC))

all: ${NAME}

${NAME}: ${OBJ}
	@echo ${Blue} Building ${NAME} ${Color_Off}
	@${MAKE} -C libft
	@${CC} $^ ${LIBS} ${FLAGS} -o ${NAME}
	@echo ${Green} Complete 😊 ${Color_off}

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) | $(OBJ_DIR)
	@echo ${Blue} Compiling: $< ${Color_Off}
	@${CC} ${FLAGS} ${HEADER} -c $< -o $@


$(OBJ_DIR):
	@mkdir $@

# Set 'WITH_BONUS' option to make with bonus
bonus:
	@${MAKE} WITH_BONUS=1 all

clean:
	@echo ${Yellow} Deleting ${OBJ_DIR} ${Color_off}
	@${MAKE} -C libft fclean
	@${RM} ${OBJ_DIR}

fclean: clean
	@echo ${Yellow} Deleting ${NAME} ${Color_off}
	@${MAKE} -C libft fclean
	@${RM} ${NAME} checker

re:	fclean all

.PHONY: all bonus clean fclean re
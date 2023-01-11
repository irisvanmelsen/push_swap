# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 13:51:13 by ivan-mel          #+#    #+#              #
#    Updated: 2023/01/10 18:46:02 by ivan-mel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	push_swap
LIBS		=	./libft/libft.a
HEADER		=	-I ${LIBFT}
HEADERS		=	libft/libft.h
#UTILS
RM 			=	rm -rf
FLAGS 		=	-Wall -Werror -Wextra
CC 			= 	gcc
SRC			=	checker.c\
#SRCB		=	
OBJ_FILES	=	${SRC:.c=.o}
#OBJB_FILES	=	${SRCB:.c=.o}
OBJ_DIR	=	./obj/
SRC_DIR = 	./src/
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

# Add obj directory to obj path
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_RAW))

# libs:
# 	@${MAKE} -C libft

# all:
# 	libs ${NAME}

${NAME}: ${OBJ}
	@echo ${Blue} Building ${NAME} ${Color_Off}
	@${MAKE} -C libft
	@${CC} $^ ${LIBS} -o ${NAME}
	@echo ${Green} Complete 😊 ${Color_off}

$(OBJ_DIR)%.o: %.c
	@mkdir -p ${OBJ_DIR}
	@echo ${Blue} Compiling: $< ${Color_Off}
	@${CC} ${FLAGS} ${HEADER} -c $< -o $@

clean:
	@echo ${Yellow} Deleting ${OBJ_DIR} ${Color_off}
	@${MAKE} -C libft fclean
	@${RM} ${OBJ_DIR}

fclean: clean
	@echo ${Yellow} Deleting ${NAME} ${Color_off}
	@${MAKE} -C libft fclean
	@${RM} ${NAME}

re:	fclean all
.PHONY: all clean fclean re
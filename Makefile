# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 13:51:13 by ivan-mel          #+#    #+#              #
#    Updated: 2023/01/04 15:03:46 by ivan-mel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	push_swap
RM 			=	rm -rf
FLAGS 		=	-Wall -Werror -Wextra
CC 			= 	gcc
AR 			=	ar -rc
SRC			=	push.c\
				checker.c\
#SRCB		=	
OBJ_FILES	=	${SRC:.c=.o}
#OBJB_FILES	=	${SRCB:.c=.o}
OBJ_DIR	=	./obj/
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
all:	${NAME}
${NAME}: ${OBJ}
	@echo ${Blue} Building ${NAME} ${Color_Off}
	@${AR} ${NAME} $?
	@echo ${Green} Complete 😊 ${Color_off}

$(OBJ_DIR)%.o: %.c
	@mkdir -p ${OBJ_DIR}
	@echo ${Blue} Compiling: $< ${Color_Off}
	@${CC} ${FLAGS} -c $< -o $@

clean:
	@echo ${Yellow} Deleting ${OBJ_DIR} ${Color_off}
	@${RM} ${OBJ_DIR}

fclean: clean
	@echo ${Yellow} Deleting ${NAME} ${Color_off}
	@${RM} ${NAME}

re:	fclean all
.PHONY: all clean fclean re
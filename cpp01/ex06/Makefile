# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ego <ego@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/10 15:08:01 by ego               #+#    #+#              #
#    Updated: 2025/06/11 22:25:48 by ego              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SDIR		=	./
SRCS		=	main.cpp	\
				Harl.cpp
ODIR		=	objs/
OBJS		=	$(addprefix $(ODIR), $(SRCS:.cpp=.o))
IDIR		=	.
INCL		=	-I $(IDIR)

CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98
RM			=	rm -rf

NAME		=	harlFilter

all			:	$(NAME)

$(NAME)		:	$(ODIR) $(OBJS)
				$(CC) $(CFLAGS) $(INCL) $(OBJS) -o $(NAME)
				printf "$(COLOR_G)[OK] $(NAME) is ready!$(C_RESET)\n" || \
				printf "$(COLOR_R)[KO] Something went wrong.$(C_RESET)\n"

$(ODIR)		:
				mkdir -p $(ODIR)
				printf "Object directory created.\n"

$(ODIR)%.o	:	$(SDIR)%.cpp
				echo "Compiling $<..."
				$(CC) $(CFLAGS) $(INCL) -c $< -o $@ || \
				(printf "$(COLOR_R)[KO] Compilation failed.$(C_RESET)\n" && false)

clean		:
				echo "Removing object files..."
				$(RM) $(ODIR)
				printf "$(COLOR_O)[OK] All object files have been removed.$(C_RESET)\n"

fclean		:	clean
				echo "Removing binary files..."
				$(RM) $(NAME)
				printf "$(COLOR_O)[OK] All binary files have been removed.$(C_RESET)\n"

re			:	fclean all

.PHONY		:	all clean fclean re
.SILENT		:	all $(NAME) $(ODIR) $(OBJS) clean fclean re

COLOR_R		= \033[31m
COLOR_O		= \033[38;5;214m
COLOR_Y		= \033[33m
COLOR_G		= \033[32m
COLOR_B		= \033[34m
COLOR_V		= \033[38;5;93m
COLOR_I		= \033[3m
C_RESET		= \033[0m
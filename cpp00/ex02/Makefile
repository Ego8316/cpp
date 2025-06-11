# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ego <ego@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/10 15:08:01 by ego               #+#    #+#              #
#    Updated: 2025/06/11 17:11:43 by ego              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SDIR		=	./
SRCS		=	tests.cpp	\
				Account.cpp
ODIR		=	objs/
OBJS		=	$(addprefix $(ODIR), $(SRCS:.cpp=.o))
IDIR		=	.
INCL		=	-I $(IDIR)

CC			=	g++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98
RM			=	rm -rf

NAME		=	account
LOG			=	original.log

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

$(LOG)		:
				echo "Fetching original log..."
				wget https://cdn.intra.42.fr/document/document/34946/19920104_091532.log -q -O $(LOG) && \
				echo "$(COLOR_G)[OK] Original log file downloaded. $(C_RESET)" || \
				echo "$(COLOR_R)[KO] Could not download original log file. $(C_RESET)"

lclean		:
				$(RM) $(LOG) test.log timestamp.txt stripped_test.log stripped_original.log

test		:	$(LOG) $(NAME)
				./$(NAME) > test.log
				echo "Checking timestamp..."
				awk 'NR==1 { gsub(/\[|\]/, "", $$1); print $$1 }' test.log > timestamp.txt
				ts=$$(cat timestamp.txt); \
				if [ -z "$$ts" ]; then \
					echo "$(COLOR_R)[KO] No timestamp found!$(C_RESET)"; \
					make -s lclean; \
					exit 1; \
				fi; \
				ts_date=$${ts%_*}; \
				ts_hour=$${ts#*_}; \
				today_date=$$(date +%Y%m%d); \
				today_hour=$$(date +%H%M%S); \
				if [ "$$ts_date" = "$$today_date" ] && [ "$$ts_hour" = "$$today_hour" ]; then \
					echo "$(COLOR_G)[OK] Date OK: $$ts_date $$ts_hour$(C_RESET)"; \
				else \
					echo "$(COLOR_R)[KO] Date MISMATCH: $$ts_date $$ts_hour != $$today_date $$today_hour$(C_RESET)"; \
					make -s lclean; \
					exit 1; \
				fi
				echo "Checking content..."
				cut -d " " -f2- test.log > stripped_test.log
				cut -d " " -f2- $(LOG) > stripped_original.log
				diff stripped_test.log stripped_original.log > /dev/null ; \
				if [ $$? -eq 0 ]; then \
					echo "$(COLOR_G)[OK] Output content matches original.$(C_RESET)" ; \
				else \
					echo "$(COLOR_R)[KO] Output content differs from original.$(C_RESET)" ; \
					diff stripped_test.log stripped_original.log ; \
					make -s lclean; \
					exit 1; \
				fi
				make -s lclean

re			:	fclean all

.PHONY		:	all clean fclean re $(LOG)
.SILENT		:	all $(NAME) $(ODIR) $(OBJS) clean fclean re $(LOG) test

COLOR_R		= \033[31m
COLOR_O		= \033[38;5;214m
COLOR_Y		= \033[33m
COLOR_G		= \033[32m
COLOR_B		= \033[34m
COLOR_V		= \033[38;5;93m
COLOR_I		= \033[3m
C_RESET		= \033[0m
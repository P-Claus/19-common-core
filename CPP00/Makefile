#############################################
###		 CONFIG		          ###
#############################################

NAME			= megaphone

CC			= c++
RM			= rm -rf
CFLAGS			= -Wall -Werror -Wextra -std=c++98

MKDIR			= mkdir -p

SOURCE_FILE		= try.cpp
OBJ_FILES		= try.o

#############################################
###		COLORS			  ###
#############################################

RED			= \033[0;31m
GREEN			= \033[0;32m
YELLOW			= \033[0;33m
BLUE			= \033[0;34m
MAGENTA			= \033[0;35m
CYAN			= \033[0;36m
RESET_COLOR		= \033[0m
MOVEUP			= \033[F
RESET			= \e[2K\r

#############################################
###		RULES	      		  ###
#############################################

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES)
	@echo "$(GREEN)Compiled try$(RESET_COLOR)"

$(OBJ_FILES): $(SOURCE_FILE)
	@$(CC) $(CFLAGS) -c $< -o $@ 


clean:
	@$(RM) $(OBJ_FILES)
	@echo "$(GREEN)Removed the object files$(RESET_COLOR)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(GREEN)Removed the executable$(RESET_COLOR)"

re:
	@make -s fclean
	@make -s

.PHONY:	all clean fclean re

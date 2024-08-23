#############################################
###		 			CONFIG		          ###
#############################################

NAME			= megaphone

CC				= c++
RM				= rm -rf
CFLAGS			= -Wall -Werror -Wextra -std=c++98

MKDIR			= mkdir -p

SOURCE_FILE		= ex00.cpp 
OBJ_FILES		= ex00.o

#############################################
###					RULES	      		  ###
#############################################

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES)

$(OBJ_FILES): $(SOURCE_FILE)
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	$(RM) $(OBJ_FILES)

fclean: clean
	$(RM) $(NAME)

re:
	make -s fclean
	make -s

.PHONY:	all clean fclean re

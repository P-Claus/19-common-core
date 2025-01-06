#############################################
###		 			CONFIG		          ###
#############################################

NAME			= horde 

CC			= c++
RM			= rm -rf
CFLAGS			= -Wall -Werror -Wextra -std=c++98

MKDIR			= mkdir -p

INCLUDES		= I ./includes

SOURCE_FILES		= main.cpp Zombie.cpp zombieHorde.cpp
SOURCES_DIR		= src
SOURCES			= $(addprefix $(SOURCES_DIR)/, $(SOURCE_FILES))

OBJ_DIR			= obj
OBJ_FILES		= $(addprefix $(OBJ_DIR)/, $(notdir $(SOURCES:.cpp=.o)))



#############################################
###					RULES	      		  ###
#############################################

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES)

$(OBJ_DIR)/%.o: $(SOURCES_DIR)/%.cpp
	$(MKDIR) $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re:
	make -s fclean
	make -s

.PHONY:	all clean fclean re

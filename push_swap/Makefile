#########################################
###		 		CONFIG	      	      ###
#########################################

NAME			= push_swap

CC				= cc
RM				= rm -rf
CFLAGS			= -Wall -Werror -Wextra -g $(INCLUDES)


LIBFT_DIR		= ./libft
LIBFT			= ./libft/libft.a
LIBFT_SOURCES	= $(LIBFT_DIR)/*.c
LIBFT_OBJ		= $(LIBFT_DIR)/*.o

MKDIR			= mkdir -p

SOURCES_DIR		= src
SOURCES			= $(wildcard $(SOURCES_DIR)/*.c)
OBJ				= $(addprefix $(OBJ_DIR)/, $(notdir $(SOURCES:.c=.o)))
OBJ_DIR			= obj

ERROR_DIR		= error
ERROR_FILES		= $(wildcard $(ERROR_DIR)/*.c)
ERROR_OBJ		= $(addprefix $(OBJ_DIR)/, $(notdir $(ERROR_FILES:.c=.o)))

ACTIONS_DIR		= actions
ACTIONS_FILES	= $(wildcard $(ACTIONS_DIR)/*.c)
ACTIONS_OBJ		= $(addprefix $(OBJ_DIR)/, $(notdir $(ACTIONS_FILES:.c=.o)))

UTILS_DIR 		= utils
UTILS_FILES		= $(wildcard $(UTILS_DIR)/*.c)
UTILS_OBJ		= $(addprefix $(OBJ_DIR)/, $(notdir $(UTILS_FILES:.c=.o)))

INCLUDES		= -I ./includes

TOTAL_FILES := $(words $(wildcard $(SOURCES_DIR)/*.c) $(wildcard $(ERROR_DIR)/*.c) $(wildcard $(ACTIONS_DIR)/*.c) $(wildcard $(UTILS_DIR)/*.c))

COMPILE_COUNT = 0

#########################################
###					COLORS		      ###
#########################################

RED				= \033[0;31m
GREEN			= \033[0;32m
YELLOW			= \033[0;33m
BLUE			= \033[0;34m
MAGENTA			= \033[0;35m
CYAN			= \033[0;36m
RESET_COLOR		= \033[0m
MOVEUP			= \033[F
RESET			= \e[2K\r

#########################################
###		 		RULES	      	      ###
#########################################

all: $(NAME)

$(LIBFT): 
	@make -s -C $(LIBFT_DIR) 

$(NAME): $(LIBFT) $(OBJ) $(UTILS_OBJ) $(ERROR_OBJ) $(ACTIONS_OBJ) 
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(UTILS_OBJ) $(ERROR_OBJ) $(ACTIONS_OBJ) $(LIBFT)
	@echo "$(RESET)$(GREEN)Compiled $(NAME)$(RESET_COLOR)"

$(OBJ_DIR)/%.o: $(SOURCES_DIR)/%.c
	@$(MKDIR) $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(eval COMPILE_COUNT=$(shell echo $$(($(COMPILE_COUNT)+1))))
	@echo -n "$(RESET)$(YELLOW)Compiling push_swap $$(($(COMPILE_COUNT)*100/$(TOTAL_FILES)))%"

$(OBJ_DIR)/%.o: $(UTILS_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(eval COMPILE_COUNT=$(shell echo $$(($(COMPILE_COUNT)+1))))
	@echo -n "$(RESET)$(YELLOW)Compiling push_swap $$(($(COMPILE_COUNT)*100/$(TOTAL_FILES)))%"

$(OBJ_DIR)/%.o: $(ERROR_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(eval COMPILE_COUNT=$(shell echo $$(($(COMPILE_COUNT)+1))))
	@echo -n "$(RESET)$(YELLOW)Compiling push_swap $$(($(COMPILE_COUNT)*100/$(TOTAL_FILES)))%"

$(OBJ_DIR)/%.o: $(ACTIONS_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(eval COMPILE_COUNT=$(shell echo $$(($(COMPILE_COUNT)+1))))
	@echo -n "$(RESET)$(YELLOW)Compiling push_swap $$(($(COMPILE_COUNT)*100/$(TOTAL_FILES)))%"

clean:
	@make clean -s -C $(LIBFT_DIR)
	@$(RM) $(OBJ_DIR)
	@echo "$(GREEN)Removed the object files from push_swap$(RESET_COLOR)"

fclean:
	@make fclean -s -C $(LIBFT_DIR)
	@$(RM) $(OBJ_DIR)
	@$(RM) $(NAME)
	@echo "$(GREEN)Removed $(NAME) and the object files$(RESET_COLOR)"

re:
	@make fclean
	@make



.PHONY:			all clean fclean re 
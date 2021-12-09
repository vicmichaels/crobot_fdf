NAME = fdf

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = ./libft/

MINILIBX = $(MINILIBX_DIR)libmlx.a
MINILIBX_DIR = ./minilibx_macos/
FW = -framework OpenGL -framework AppKit

LIBS =  $(FW) $(MINILIBX) $(LIBFT)

HEAD = ./inc/

SRC_DIR = ./src/
SRC_FILES = init.c fdf.c draw.c read.c math.c\
 param.c controls.c customize.c colour.c rotation.c
SRC = $(SRC_DIR) $(SRC_FILES)

OBJ_DIR = obj/
OBJ_FILES = $(patsubst %.c, %.o, $(SRC_FILES))
OBJ	= $(addprefix $(OBJ_DIR), $(OBJ_FILES))

CC = gcc
FLAGS = -Wall -Werror -Wextra -g
INC = -I$(HEAD)

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(MINILIBX) $(LIBFT) $(OBJ_DIR) $(OBJ)
	@$(CC) $(FLAGS) $(LIBS) $(INC) $(FW) $(OBJ) -o $(NAME)
	@echo "$(GREEN)$(NAME) CREATED!$(RESET)"

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HEAD)
	$(CC) $(FLAGS) -c $(INC) $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)
	@echo "$(GREEN)LIBFT OK!$(RESET)"

$(MINILIBX):
	@make -C $(MINILIBX_DIR)
	@echo "$(GREEN)MINILIBX OK!$(RESET)"

clean:
	@make -sC $(LIBFT_DIR) clean
	@make -sC $(MINILIBX_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)CLEAR!$(RESET)"

fclean: clean
	@rm -f $(MINILIBX)
	@rm -f $(LIBFT)
	@rm -f $(NAME)
	@echo "$(GREEN)EXTRA CLEAR!$(RESET)"

re: fclean all
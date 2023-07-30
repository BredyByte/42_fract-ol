NAME = fractol

CC = cc
CFLAGS = -Wextra -Wall -Werror
REMOVE = rm -r

OBJ_PATH = obj
SRC_PATH = src
INC_PATH = include
MLX_PATH = MLX42
MLX_LIB_PATH = MLX42/libmlx42.a

HEADERS	= -I $(INC_PATH) -I $(MLX_PATH)/include/MLX42
LIBS = ./$(MLX_PATH)/libmlx42.a -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/"
SRC =  $(wildcard $(SRC_PATH)/*.c)
OBJ = $(SRC:$(SRC_PATH)/%.c=$(OBJ_PATH)/%.o)

B_RED = \033[1;31m
B_GREEN = \033[1;32m
BLUE = \033[36m
RESET = \033[0m
U_LINE = \033[4m

all: $(MLX_LIB_PATH) $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(LIBS) $(HEADERS) -o $@
	@echo "\n$(U_LINE)✅$(BLUE) $(NAME): Compiled ✅$(RESET) \n"

$(MLX_LIB_PATH):
	@$(MAKE) -C $(MLX_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

clean:
	@$(REMOVE) $(OBJ_PATH)
	@$(MAKE) -C $(MLX_PATH) clean

fclean: clean
	@$(REMOVE) $(NAME)
	@$(MAKE) -s -C $(MLX_PATH) fclean

re: fclean all

.PHONY: all clean fclean re

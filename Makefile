NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror -Wunreachable-code -Ofast
REMOVE = rm -r

OBJ_PATH = obj
SRC_PATH = src
INC_PATH = include

MLX_PATH = assets/MLX42
MLX_LIB_PATH = assets/MLX42/libmlx42.a

LIBFT_PATH = assets/libft
LIBFT_LIB_PATH = assets/libft/libft.a

HEADERS	= -I $(MLX_PATH)/include/MLX42 -I $(LIBFT_PATH)/include/ -I ./include

SRC =  $(wildcard $(SRC_PATH)/*.c)
OBJ = $(SRC:$(SRC_PATH)/%.c=$(OBJ_PATH)/%.o)

ORANGE = \033[1;38;5;208m
RESET = \033[0m
U_LINE = \033[4m
YELLOW = \033[1;38;5;226m

default: all
	./fractol 1

all: $(MLX_LIB_PATH) $(LIBFT_LIB_PATH) $(NAME)

.SILENT: all $(MLX_LIB_PATH) $(LIBFT_LIB_PATH) $(NAME) $(OBJ) clean fclean re

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIBFT_LIB_PATH) $(MLX_LIB_PATH) -lglfw -L "/Users/dbredykh/.brew/opt/glfw/lib/" $(HEADERS) -o $@
	echo "\n$(ORANGE)$(U_LINE)⭐️ $(NAME): Compiled ⭐️$(RESET) \n"

$(MLX_LIB_PATH):
	$(MAKE) -C $(MLX_PATH)

$(LIBFT_LIB_PATH):
	$(MAKE) -C $(LIBFT_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)
	echo "$(YELLOW)fractol Compiling:$(RESET) $(notdir $<)"
clean:
	$(REMOVE) $(OBJ_PATH)
	$(MAKE) -C $(MLX_PATH) clean
	$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	$(REMOVE) $(NAME)
	$(MAKE) -C $(MLX_PATH) fclean
	$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re $(MLX_LIB_PATH) $(LIBFT_LIB_PATH)

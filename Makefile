NAME = fractol.a

CC = cc
CFLAGS = -Wextra -Werror -Wall
REMOVE = rm -rf
ARFLAGS = ar -rcs

OBJ_PATH = obj
SRC_PATH = src
INC_PATH = inc

SRC := $(wildcard $(SRC_PATH)/*.c)
OBJ = $(addprefix $(OBJ_PATH)/, $(notdir $(SRC:.c=.o)))

.PHONY: all clean fclean re

.SILENT:

R = \033[1;31m
G = \033[1;32m
C = \033[1;36m
O = \033[1;38;5;208m
P = \033[1;38;5;141m
END = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	$(ARFLAGS) $@ $(OBJ)
	@echo "\n$(P)[Compiled $(C)'$(NAME)'$(G)successfully]\n$(END)"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC_PATH)/fractol.h
	mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -I $(INC_PATH) -c $< -o $@

clean:
	$(REMOVE) $(OBJ) $(OBJ_PATH)
	@echo "\n$(Y)[Cleaned $(C) '$(NAME)' objects $(Y)successfully]\n$(END)"

fclean: clean
	$(REMOVE) $(NAME)
	@echo "$(R)[Removed $(C) '$(NAME)' $(R)successfully]\n$(END)"

re: fclean all

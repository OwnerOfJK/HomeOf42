NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_PATH = srcs
INC_PATH = includes
OBJ_PATH = objs

SRCS = $(addprefix $(SRC_PATH)/, ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_swap.c)
OBJS = $(SRCS:$(SRC_PATH)/%.c=$(OBJ_PATH)/%.o)
INC = -I$(INC_PATH)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $@ $^
	ranlib $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	@/bin/rm -rf $(OBJ_PATH)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
NAME = cub3D
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
MINILIBX_DIR = minilibx-linux
MINILIBX = $(MINILIBX_DIR)/libmlx.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = src/main.c
OBJS = $(SRCS:.c=.o)

INCLUDES = -I$(LIBFT_DIR) -I$(MINILIBX_DIR)
FRAMEWORK = -L$(MINILIBX_DIR) -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBFT) $(FRAMEWORK)

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(MINILIBX_DIR) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MINILIBX):
	$(MAKE) -C $(MINILIBX_DIR)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MINILIBX_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)
	rm -f $(MINILIBX)

re: fclean all

.PHONY: all clean fclean re

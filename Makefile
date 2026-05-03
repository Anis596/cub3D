NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror -g 

MLX_DIR = ./minilibx-linux
MLX = -L$(MLX_DIR) -lmlx -lX11 -lXext -lXfixes -lXrandr

SRCS = main.c parsing.c parsing2.c floodfill.c textures.c utils.c
OBJS = $(SRCS:.c=.o)

LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
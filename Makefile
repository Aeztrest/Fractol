NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lm -lX11 -lXext

SRCS = fractol.c \
	src/fractol_color.c \
	src/fractol_events.c \
	src/fractol_init.c \
	src/fractol_render.c \
	src/fractol_utils_1.c \
	src/fractol_utils_2.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
MLX_DIR = minilibx-linux
LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a

all: check_mlx $(NAME)

$(NAME): $(MLX) $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX) $(MLXFLAGS)

$(LIBFT):
	@make -C $(LIBFT_DIR)
	@touch $(LIBFT)

$(MLX): $(MLX_DIR)
	@make -C $(MLX_DIR)
	@touch $(MLX)

$(MLX_DIR):
	git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR)

clean:
	rm -f $(OBJS)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)
	rm -rf $(MLX_DIR)

re: fclean all

norm:
	norminette fractol.c fractol.h ./src

.PHONY: all clean fclean re norm check_mlx

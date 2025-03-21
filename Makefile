NAME 		= so_long
CC		= cc
CFLAGS 		= -Wall -Wextra -Werror
SRCS		= so_long.c so_long_utils.c map_controller.c map_check.c game_mlx_controller.c \
		  get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \

LIBFT		= libft/libft.a

MLX_LIB		= minilibx-linux/libmlx.a

MLX_FLAGS	= -L minilibx-linux -lmlx -L/usr/X11R6/lib -lXext -lX11 -lm -lbsd

all: $(NAME)

$(NAME): $(SRCS)
	make -s -C ./libft 
	make -s -C ./minilibx-linux
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(MLX_LIB) $(MLX_FLAGS) -o $(NAME)

clean:
	make clean -s -C ./libft
	make clean -s -C ./minilibx-linux

fclean: clean
	make fclean -s -C ./libft
	rm -rf $(NAME)
	rm -rf $(MLX_LIB)

re: fclean all

.PHONY: all clean fclean bonus re
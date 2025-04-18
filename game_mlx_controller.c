/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_mlx_controller.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <<musisman@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:43:40 by musisman          #+#    #+#             */
/*   Updated: 2025/03/21 15:43:40 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "so_long.h"

static void	draw_map_utils(t_game *game, int y, int x)
{
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall, x * 64, y
			* 64);
	else if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->path, x * 64, y
			* 64);
	else if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->player, x * 64, y
			* 64);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->collectible, x * 64,
			y * 64);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->exit, x * 64, y
			* 64);
}

static void	draw_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			draw_map_utils(game, y, x);
			x++;
		}
		y++;
	}
}

void	window(t_game *game)
{
	int	i;

	i = 64;
	game->mlx = mlx_init();
	game->wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &i, &i);
	game->path = mlx_xpm_file_to_image(game->mlx, "textures/path.xpm", &i, &i);
	game->exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &i, &i);
	game->collectible = mlx_xpm_file_to_image(game->mlx, "textures/fish.xpm",
			&i, &i);
	game->player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm", &i,
			&i);
	game->win = mlx_new_window(game->mlx, game->width * i, game->height * i,
			"So Long");
	draw_map(game);
}

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	if (game->map[new_y][new_x] != '1')
	{
		if (game->map[new_y][new_x] == 'C' && game->collectibles--)
			game->map[new_y][new_x] = '0';
		else if (game->map[new_y][new_x] == 'E' && game->collectibles == 0)
			finish(game);
		if (game->map[game->player_y][game->player_x] == 'E')
			mlx_put_image_to_window(game->mlx, game->win, game->exit,
				game->player_x * 64, game->player_y * 64);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->path,
				game->player_x * 64, game->player_y * 64);
		game->player_x = new_x;
		game->player_y = new_y;
		mlx_put_image_to_window(game->mlx, game->win, game->player,
			game->player_x * 64, game->player_y * 64);
		game->moves++;
		ft_putnbr_fd(game->moves, 1);
		ft_putchar_fd('\n', 1);
	}
}

int	key_hook(int key_code, t_game *game)
{
	if (key_code == 65307)
	{
		free_game(game);
		exit(0);
	}
	else if (key_code == 'w')
		move_player(game, 0, -1);
	else if (key_code == 'a')
		move_player(game, -1, 0);
	else if (key_code == 's')
		move_player(game, 0, 1);
	else if (key_code == 'd')
		move_player(game, 1, 0);
	return (0);
}

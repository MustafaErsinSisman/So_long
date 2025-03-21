/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <<musisman@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:43:14 by musisman          #+#    #+#             */
/*   Updated: 2025/03/21 15:43:14 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "so_long.h"

void	free_game(t_game *game)
{
	free_textures(game);
	if (game->map)
		free_map(game->map, game->height);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game);
}

static char	**copy_map(t_game *game)
{
	int		i;
	char	**map_cpy;

	map_cpy = malloc((game->height * sizeof(char *)) + 1);
	if (!map_cpy)
		error_message(ERR_MEM);
	i = 0;
	while (i < game->height)
	{
		map_cpy[i] = ft_strdup(game->map[i]);
		if (!map_cpy[i])
		{
			free_game(game);
			error_message(ERR_MEM);
		}
		i++;
	}
	return (map_cpy);
}

static void	player_position(t_game *game)
{
	int	i;
	int	j;

	i = 1;
	while (i < game->height - 1)
	{
		j = 1;
		while (j < game->width - 1)
		{
			if (game->map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

static void	flood_fill(t_game *game, char **map_cpy, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->width || y >= game->height
		|| map_cpy[y][x] == '1' || map_cpy[y][x] == 'F')
		return ;
	if (map_cpy[y][x] == 'C')
		game->count++;
	if (map_cpy[y][x] == 'E')
		game->exit_count = 1;
	map_cpy[y][x] = 'F';
	flood_fill(game, map_cpy, x - 1, y);
	flood_fill(game, map_cpy, x + 1, y);
	flood_fill(game, map_cpy, x, y - 1);
	flood_fill(game, map_cpy, x, y + 1);
}

void	flood_fill_controller(t_game *game)
{
	char	**map_cpy;

	map_cpy = copy_map(game);
	if (!map_cpy)
	{
		free_game(game);
		error_message(ERR_MEM);
	}
	player_position(game);
	game->count = 0;
	flood_fill(game, map_cpy, game->player_x, game->player_y);
	if (game->exit_count != 1 || game->count != game->collectibles)
	{
		free_map(map_cpy, game->height);
		free_map(game->map, game->height);
		free(game);
		error_message(ERR_MAP_TRGT);
	}
	free_map(map_cpy, game->height);
}

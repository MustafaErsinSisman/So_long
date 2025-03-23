/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_controller.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <<musisman@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:42:45 by musisman          #+#    #+#             */
/*   Updated: 2025/03/21 15:42:45 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	is_rectangular(t_game *game)
{
	int	i;

	if (!game->map || !game->map[0])
	{
		free_game(game);
		error_message(ERR_MEM);
	}
	i = 0;
	while (i < game->height)
	{
		if (ft_strlen(game->map[i]) != (size_t)game->width)
		{
			free_game(game);
			error_message(ERR_MAP);
		}
		i++;
	}
}

static void	map_contents(t_game *game, int i, int j)
{
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			if (game->map[i][j] == 'P')
				game->player_count++;
			else if (game->map[i][j] == 'E')
				game->exit_count++;
			else if (game->map[i][j] == 'C')
				game->collectibles++;
			else if (game->map[i][j] != '1' && game->map[i][j] != '0')
			{
				free_game(game);
				error_message(ERR_MAP_CONT);
			}
		}
	}
	if (game->player_count != 1 || game->exit_count != 1
		|| !(game->collectibles >= 1))
	{
		free_game(game);
		error_message(ERR_MAP_CONT);
	}
}

static void	map_wall(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->width)
	{
		if (game->map[0][i] != '1' || game->map[game->height - 1][i] != '1')
		{
			free_game(game);
			error_message(ERR_MAP_OPEN);
		}
		i++;
	}
	i = 0;
	while (i < game->height)
	{
		if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
		{
			free_game(game);
			error_message(ERR_MAP_OPEN);
		}
		i++;
	}
}

void	map_cntrl(t_game *game)
{
	is_rectangular(game);
	game->player_count = 0;
	game->exit_count = 0;
	game->collectibles = 0;
	map_contents(game, -1, -1);
	map_wall(game);
}

void	file_extension(char *file_name)
{
	char	*str;

	str = ft_strrchr(file_name, '.');
	if (!str || ft_strncmp(str, ".ber", 5))
		error_message(ERR_FILE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <<musisman@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:22:18 by musisman          #+#    #+#             */
/*   Updated: 2025/03/21 15:22:18 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "so_long.h"

int	finish(t_game *game)
{
	free_game(game);
	ft_putstr_fd(FINISH, 1);
	exit(0);
}

void	free_textures(t_game *game)
{
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
	if (game->collectible)
		mlx_destroy_image(game->mlx, game->collectible);
	if (game->path)
		mlx_destroy_image(game->mlx, game->path);
}

int	map_height(char *file, t_game *game)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		free_game(game);
		error_message(ERR_MAP_TRGT);
	}
	i = 0;
	line = get_next_line(fd, 0);
	if (!line)
	{
		free_game(game);
		error_message(ERR_MAP);
	}
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd, 0);
	}
	close(fd);
	return (i);
}

int	read_map(t_game *game, char *file)
{
	int		i;
	int		fd;
	char	*line;
	char	**map;

	game->height = map_height(file, game);
	map = malloc((game->height) * sizeof(char *) + 1);
	if (!map)
		return (game->map = NULL, 0);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (free_game(game), error_message(ERR_MAP_TRGT), 0);
	i = 0;
	line = get_next_line(fd, 0);
	while (line)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		map[i++] = line;
		line = get_next_line(fd, 0);
	}
	close(fd);
	game->map = map;
	game->width = ft_strlen(map[0]);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		error_message(ERR_ARG);
	file_extension(argv[1]);
	game = malloc(sizeof(t_game));
	if (!game)
		error_message(ERR_MEM);
	fill_game(game);
	read_map(game, argv[1]);
	map_cntrl(game);
	game->moves = 0;
	flood_fill_controller(game);
	window(game);
	mlx_hook(game->win, 17, 0, close_game, game);
	mlx_key_hook(game->win, key_hook, game);
	mlx_loop(game->mlx);
}

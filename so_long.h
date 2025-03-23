/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <<musisman@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:24:44 by musisman          #+#    #+#             */
/*   Updated: 2025/03/21 15:24:44 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define ERR_ARG "Argument error\n"
# define ERR_MEM "Memory error\n"
# define ERR_FILE "File error\n"
# define ERR_MAP "Map error\n"
# define ERR_MAP_CONT "Map contents error\n"
# define ERR_MAP_OPEN "Map walls error\n"
# define ERR_MAP_TRGT "Map target error\n"
# define FINISH "Thanks for playing\n"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*wall;
	void	*path;
	void	*exit;
	void	*collectible;
	void	*player;
	char	**map;
	int		width;
	int		height;
	int		exit_count;
	int		player_count;
	int		player_x;
	int		player_y;
	int		count;
	int		collectibles;
	int		moves;
}			t_game;

int			read_map(t_game *game, char *file);
int			key_hook(int key_code, t_game *game);
int			finish(t_game *game);
int			close_game(t_game *game);
void		free_game(t_game *game);
void		free_textures(t_game *game);
void		error_message(char *err);
void		file_extension(char *filename);
void		fill_game(t_game *game);
void		map_cntrl(t_game *game);
void		free_game(t_game *game);
void		free_map(char **map, int height);
void		flood_fill_controller(t_game *game);
void		window(t_game *game);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <musisman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:35:23 by musisman          #+#    #+#             */
/*   Updated: 2025/03/20 15:15:35 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include <fcntl.h>

# include <stdio.h>

# define ERR_ARG "Argument error\n"
# define ERR_MEM "Memory error\n"
# define ERR_FILE "File error\n"
# define ERR_MAP "Map error\n"


typedef struct s_game
{
// 	void	*mlx;
// 	void	*win;
// 	void	*wall;
// 	void	*path;
// 	void	*exit;
// 	void	*collectible;
// 	void	*player;
	char	**map;
	int		width;
	int		height;
	int		exit_count;
	int		player_count;
// 	int		player_x;
// 	int		player_y;
// 	int		count;
	int		collectibles;
// 	int		moves;
}			t_game;

void error (char *err_msg);
void fill_game(t_game *game);
void file_control(t_game *game, char *av);

#endif
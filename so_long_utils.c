/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <<musisman@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 08:30:43 by musisman          #+#    #+#             */
/*   Updated: 2025/03/20 08:30:43 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void error (char *err_msg)
{
        ft_putstr_fd(err_msg, 2);
        exit(1);
}

void fill_game(t_game *game)
{
//      game->mlx;
//      game->win;
//      game->wall;
//      game->path;
//      game->exit;
//      game->collectible;
//      game->player;
	game->map = NULL;
	game->width = 3;
        game->height = 3;
        game->exit_count = 0;
        game->player_count = 0;
// 	game->player_x;
// 	game->player_y;
// 	game->count;
        game->collectibles = 0;
// 	game->moves;
}

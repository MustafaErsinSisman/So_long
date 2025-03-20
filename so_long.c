/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <<musisman@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:35:22 by musisman          #+#    #+#             */
/*   Updated: 2025/03/20 09:26:40 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game *game;

	if (ac != 2)
		error(ERR_ARG);
	game = malloc(sizeof(game));
	if (!game)
		error(ERR_MEM);
	fill_game(game);
	file_control(game, av[1]);
	
	return (0);
}

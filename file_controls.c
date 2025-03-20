/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <<musisman@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 08:40:24 by musisman          #+#    #+#             */
/*   Updated: 2025/03/20 08:40:24 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_control(t_game *game, char *line, int len)
{
	int	i;

	if (len != game->width && (len + 1) != game->width)
		error(ERR_MAP);
        i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == '1' || line[i] == '0' || line[i] == 'E'
			|| line[i] == 'C' || line[i] == 'P')
                        i++;
		else
                        error(ERR_MAP);
	}
}
// hraitayı ilk başta copy map ile içinde tut sonra onra göre işelm yap !!! ~ Yusuf Taha Özlü 
void	read_map(t_game *game, int fd)
{
	int		len;
	char	*line;
	int i;
	i = 0;
	while (1)
	{
		line = get_next_line(fd, 0);
		if (!line)
		{
			get_next_line(fd, 1);
			free (line);
			break ;
		}
		if (ft_strlen(line) < 3)
			error(ERR_MAP);
		if (i++ == 0)
			game->width = ft_strlen(line);
		len = ft_strlen(line);
		map_control(game, line, len);
		free(line);
	}
	game->height = i;
}

void right_map(t_game *game, int fd)
{

}

void	file_control(t_game *game, char *av)
{
	int	fd;

	if (!ft_strnstr(av, ".ber", ft_strlen(av)))
		error(ERR_FILE);
	fd = open(av, O_RDONLY);
	if (fd < 0)
		error(ERR_FILE);
	read_map(game, fd);
	right_map(game,fd);
}

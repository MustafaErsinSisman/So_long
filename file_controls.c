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

	if (len != game->width)
	{
		printf("len hata\n");
		error(ERR_MAP);
	}
        i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == '1' || line[i] == '0' || line[i] == 'E'
			|| line[i] == 'C' || line[i] == 'P' || line[i] == '\r')
                        i++;
		else
                {
                        printf("%c %d %d\n", line[i], line[i], i);
                        error(ERR_MAP);
                }
	}
}

void	read_map(t_game *game, int fd)
{
	int		len;
	char	*line;
	// char	**map;

	line = get_next_line(fd, 0);
	len = ft_strlen(line) - 1;
	if (line[len - 1] == '\n')
		len--;
	game->width = len;
	while (1)
	{
		printf("%s\n", line);
		map_control(game, line, len);
		if (!line)
		{
			get_next_line(fd, 1);
			free (line);
			break ;
		}
		free(line);
		line = get_next_line(fd, 0);
		len = ft_strlen(line);
	}
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
}

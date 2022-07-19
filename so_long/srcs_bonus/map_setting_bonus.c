/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setting_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:12:30 by sumjang           #+#    #+#             */
/*   Updated: 2022/07/19 22:12:51 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_init(t_game *gmae, char *filename);
void	read_map(t_game *game, char *filename);
void	is_valid_map(t_game *game);
void	is_valid_char(t_game *game, int x, int y);

void	map_init(t_game *game, char *filename)
{
	int	i;

	game->map = NULL;
	read_map(game, filename);
	game->size_y = ft_strlen(game->map[0]);
	i = 0;
	while (game->map[i])
		i++;
	game->size_x = i;
	game->movement = 0;
	game->collectible = 0;
	game->exit = 0;
	game->player = 0;
	is_valid_map(game);
}

void	read_map(t_game *game, char *filename)
{
	int		fd;
	char	*line;
	char	*lines;
	char	*tmp;

	lines = NULL;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_perror_exit("Error\nFile open fail\n");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		tmp = lines;
		lines = ft_strjoin(lines, line);
		free(line);
		free(tmp);
	}
	if (lines == NULL)
		ft_perror_exit("Error\n: Map is empty\n");
	game->map = ft_split(lines, '\n');
	free(lines);
	if (close(fd) == -1)
		ft_perror_exit("Error\n");
}

void	is_valid_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->size_x)
	{
		y = 0;
		while (y < game -> size_y)
		{
			if (game->map[x][y] != '1' && \
			(x == 0 || x == game->size_x - 1 || \
			y == 0 || y == game->size_y - 1))
				ft_perror_exit("Error\n: Map must be closed/surrounded \
						by walls\n");
			if (y == game->size_y - 1 && game->map[x][y + 1])
				ft_perror_exit("Error\n: Map must be rectangular\n");
			is_valid_char(game, x, y);
			y++;
		}
		x++;
	}
	if (game->collectible < 1 || game->exit < 1 || game->player != 1)
		ft_perror_exit("Error\n: Map must have at least one exit, \
				one collectible, and one starting position\n");
}

void	is_valid_char(t_game *game, int x, int y)
{
	char	c;

	c = game->map[x][y];
	if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
		ft_perror_exit("Error\n: Map must be composed of \
				only 5 possible characters\n");
	if (c == 'C')
		game->collectible++;
	else if (c == 'E')
		game->exit++;
	else if (c == 'P')
	{
		game->player++;
		game->x = x;
		game->y = y;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_setting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:11:58 by sumjang           #+#    #+#             */
/*   Updated: 2022/07/19 21:27:50 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	img_init(t_game *game);
void	put_image_to_window_all(t_game *game);
void	put_image_to_window(t_game *game, int x, int y);

t_img	img_init(t_game *game)
{
	t_img	i;
	int		x;
	int		y;

	i.ground = mlx_xpm_file_to_image(game->mlx_ptr, \
			"./imgs/ground.xpm", &x, &y);
	i.wall = mlx_xpm_file_to_image(game->mlx_ptr, "./imgs/wall.xpm", &x, &y);
	i.exit = mlx_xpm_file_to_image(game->mlx_ptr, "./imgs/exit.xpm", &x, &y);
	i.collectible = mlx_xpm_file_to_image(game->mlx_ptr, \
			"./imgs/star.xpm", &x, &y);
	i.player = mlx_xpm_file_to_image(game->mlx_ptr, \
			"./imgs/player.xpm", &x, &y);
	if (!(i.ground) || !(i.wall) || !(i.collectible) || \
			!(i.exit) || !(i.player))
		ft_perror_exit("Error\n: mlx_xpm_file_to_image() failed\n");
	else if (!(x == TILE_SIZE && y == TILE_SIZE))
		ft_perror_exit("Error\nincorrect tile size\n");
	return (i);
}

void	put_image_to_window_all(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->size_x)
	{
		y = 0;
		while (y < game->size_y)
		{
			put_image_to_window(game, x, y);
			y++;
		}
		x++;
	}
}

//두번째 코드랑 비교 !!!필요함!!
//static void?
void	put_image_to_window(t_game *game, int x, int y)
{
	void	*img_p;

	if (game->map[x][y] == '1')
		img_p = game->img.wall;
	else if (game->map[x][y] == 'C')
		img_p = game->img.collectible;
	else if (game->map[x][y] == 'E')
		img_p = game->img.exit;
	else if (game->map[x][y] == 'P')
		img_p = game->img.player;
	else
		img_p = game->img.ground;
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			img_p, y * TILE_SIZE, x * TILE_SIZE);
}

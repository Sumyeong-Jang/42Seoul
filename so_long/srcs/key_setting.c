/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_setting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:12:05 by sumjang           #+#    #+#             */
/*   Updated: 2022/07/13 15:12:06 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int		key_hook(int keycode, t_game *game);
int		exit_game(t_game *game);
void	change_map(int key, t_game *game);
void	move_player(t_game *game, int newline, int newcol);

int	key_hook(int keycode, t_game *game)
{
	if (keycode == ESC)
		exit_game(game);
	else if (keycode == W)
		change_map(0, game);
	else if (keycode == A)
		change_map(1, game);
	else if (keycode == S)
		change_map(2, game);
	else if (keycode == D)
		change_map(3, game);
	return (0);
}

int	exit_game(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->img.ground);
	mlx_destroy_image(game->mlx_ptr, game->img.wall);
	mlx_destroy_image(game->mlx_ptr, game->img.collectible);
	mlx_destroy_image(game->mlx_ptr, game->img.exit);
	mlx_destroy_image(game->mlx_ptr, game->img.player);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	exit(EXIT_SUCCESS);
}

void	change_map(int key, t_game *game)
{
	int			x_new;
	int			y_new;
	char		new_position;
	const int	x[4] = {-1, 0, 1, 0};
	const int	y[4] = {0, -1, 0, 1};

	x_new = game->x + x[key];
	y_new = game->y + y[key];
	new_position = game->map[x_new][y_new];
	if (new_position == '1')
		return ;
	if (new_position == 'E' && game->collectible)
		return ;
	if (new_position == 'E')
	{
		move_player(game, x_new, y_new);
		put_image_to_window_all(game);
		exit_game(game);
	}
	if (new_position == 'C')
		game->collectible -= 1;
	move_player(game, x_new, y_new);
	put_image_to_window_all(game);
}

void	move_player(t_game *game, int x_new, int y_new)
{
	game->map[game->x][game->y] = '0';
	game->x = x_new;
	game->y = y_new;
	game->map[game->x][game->y] = 'P';
	game->movement += 1;
	printf("Your current number of movements: %d\n", game->movement);
}

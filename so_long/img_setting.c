/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_setting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:11:58 by sumjang           #+#    #+#             */
/*   Updated: 2022/07/13 15:12:02 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    img_init(t_game *game);
void    put_image_to_window_all(t_game *game);
void    put_image_to_window(t_game *game, int x, int y);

void    img_init(t_game *game)
{
    int     x;
    int     y;

    game->imgs->empty = mlx_xpm_file_to_image(game->mlx, "./imgs/empty.xpm", &x, &y);
    game->imgs->wall = mlx_xpm_file_to_image(game->mlx, "./imgs/wall.xpm", &x, &y);
    game->imgs->collectible = mlx_xpm_file_to_image(game->mlx, "./imgs/collectible.xpm", &x, &y);
    game->imgs->exit = mlx_xpm_file_to_image(game->mlx, "./imgs/exit.xpm", &x, &y);
    game->imgs->player = mlx_xpm_file_to_image(game->mlx, "./imgs/player.xpm", &x, &y);
    if (!(game->imgs->empty) || !(game->imgs->wall) || \
    !(game->imgs->collectible) || !(game->imgs->exit) || \
    !(game->imgs->player))
        ft_pstr_exit("Error\n: mlx_xpm_file_to_image() failed..");
}

void    put_image_to_window_all(t_game *game)
{
    int x;
    int y;

    x = 0;
    while (x < game->x)
    {
        y = 0;
        while (y < game->y)
        {
            put_image_to_window(game, x, y);
            y++;
        }
        x++;
    }
}

//두번째 코드랑 비교 !!!필요함!!
//static void?
void    put_image_to_window(t_game *game, int x, int y)
{
    void    *img_p;

    if (game->map[x][y] == '1')
        img_p = game->imgs->wall;
    else if (game->map[x][y] == 'C')
        img_p = game->imgs->collecible;
    else if (game->map[x][y] == 'E')
        img_p = game->imgs->exit;
    else if (game->map[x][y] == 'P')
        img_p = game->imgs->player;
    else
        img_p = game->imgs->empty;
    mlx_put_image_to_window(game->mlx, game->win, img_p, x * PIXEL, y * PIXEL);
}

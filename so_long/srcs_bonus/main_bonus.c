/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:12:15 by sumjang           #+#    #+#             */
/*   Updated: 2022/07/19 22:12:04 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		is_valid_arg(int argc, char *argv);
void	game_init(t_game *g, char *map);

void	print_err(char *message);
int		exit_game(t_game *game);
int		press_key(int key_code, t_game *game);

//extern int가 모얌?
//저게 있으면 main 함수 return(0)이 없어도 되는건가?
int	main(int argc, char *argv[])
{
	t_game	*game;

	if (argc != 2)
		ft_perror_exit("Error\nMap is missing\n");
	if (!is_valid_arg(argc, argv[1]))
		ft_perror_exit("Error\nArgument Error\n");
	game = malloc(sizeof(t_game));
	if (!game)
		return (0);
	game_init(game, argv[1]);
	printf("game_init complete\n");
	mlx_hook(game->win_ptr, KEY_PRESS, 0, &key_hook, game);
	mlx_hook(game->win_ptr, DESTROY_NOTIFY, 0, &exit_game, game);
	mlx_loop(game->mlx_ptr);
	return (0);
}

int	is_valid_arg(int argc, char *filename)
{
	if (ft_strlen(filename) < 5 || (ft_strrchr(filename, '.') \
	&& ft_strncmp(ft_strrchr(filename, '.'), ".ber", 5)))
		return (0);
	else
		return (1);
}

void	game_init(t_game *game, char *filename)
{
	map_init(game, filename);
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		ft_perror_exit("Error\n: mlx_init() failed\n");
	game->win_ptr = mlx_new_window(game->mlx_ptr, \
			game->size_y * TILE_SIZE, game->size_x * TILE_SIZE, "so_long");
	if (!game->win_ptr)
		ft_perror_exit("Error\n: mlx_new_window() failed\n");
	game->img = img_init(game);
	put_image_to_window_all(game);
}

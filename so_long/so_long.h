/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:12:21 by sumjang           #+#    #+#             */
/*   Updated: 2022/07/13 16:14:22 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "./mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>

# define KEY_PRESS	2
//# define X_EVENT_KEY_RELEASE		3
# define KEY_EXIT	17//DESTROY_NOTIFYF

# define ESC		53
# define W			13
# define A			0
# define S			1
# define D			2

# define PIXEL 64 // pixel 꼭 define으로 정의해야함?
//그리고 pixel은 원래 64로 고정인가?

typedef struct s_img {
	void	*empty;
	void	*wall;
	void	*collectible;
	void	*land;
	void	*exit;
	void	*player;
}				t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_img	img;
	char	**map;
	int		size_x;
	int		size_y;
	int		x;
	int		y;
	char	*str_line;
	int	collectible;//인자 확인
	int		exit;
	int		player;
	//int		all_col;
	//int		col_cnt;
	int		movement;
}				t_game;

/*	utils	*/
void	ft_perror_exit(char *s);
void	ft_pstr_exit(char *s);

/*	img_setting.c	*/
t_img	img_init(t_game *game);
void	put_image_to_window_all(t_game *game);
void	put_image_to_window(t_game *game, int x, int y);

/*	map_setting.c	*/
void	map_init(t_game *gmae, char *filename);
void	read_map(t_game *game, char *filename);
void	is_valid_map(t_game *game);
void	is_valid_char(t_game *game, int x, int y);

/*	key_setting.c	*/
int		key_hook(int keycode, t_game *game);
int		exit_game(t_game *game);
void	change_map(int key, t_game *game);
static void	move_player(t_game *game, int newline, int newcol);

/*	so_long	*/
void	print_err(char *message);
void	game_init(t_game *g, char *map);
int		exit_game(t_game *game);
int		press_key(int key_code, t_game *game);
int		main(int ac, char *av[]);

#endif

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

# include "./get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

# define KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3

# define KEY_EXIT	17
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
	int		x;
	int		y;
	char	*str_line;
    int     collectible;//인자 확인
	int		exit;
	int		player;
	int		all_col;
	int		col_cnt;
	int		movement;
}				t_game;

/*	img_setting.c	*/
void    img_init(t_game *game);
void    put_image_to_window_all(t_game *game);
void    put_image_to_window(t_game *game, int x, int y);

/*	map_setting.c	*/
void	map_read(char *filename, t_game *game);
void	map_check_wall(t_game *game);
void	map_check_params(t_game *game);
void	map_check(t_game *game);

/*	key_setting.c	*/
int     key_hook(int keycode, t_game *game);
int     exit_game(t_game *game);
void    change_map(int key, t_game *game);
static void	move_player(t_game *game, int newline, int newcol);

int		clear_game(t_game *game);
void	move_w(t_game *g);
void	move_a(t_game *g);
void	move_s(t_game *g);
void	move_d(t_game *g);

/*	so_long	*/
void	print_err(char *message);
void	game_init(t_game *g, char *map);
int		exit_game(t_game *game);
int		press_key(int key_code, t_game *game);
int		main(int ac, char *av[]);

#endif

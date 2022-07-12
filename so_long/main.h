#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include "./get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

# define KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3

# define KEY_EXIT		17
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
	int		x;
	int		y;
	char	*str_line;
    int     collectible;//인자 확인
	int		all_col;
	int		col_cnt;
	int		movement;
}				t_game;

/*
	utils.c
*/
char	*ft_strdup_without_newline(char *s);
int		ft_strlcpy_without_newline(char *dst, char *src, int len);
char	*ft_strjoin_without_newline(char *s1, char *s2);

/*
	image.c
*/
t_img	img_init(void *mlx);
void	put_img(t_game *g, int w, int h);
void	setting_img(t_game *game);

/*
	map.c
*/
void	map_read(char *filename, t_game *game);
void	map_check_wall(t_game *game);
void	map_check_params(t_game *game);
void	map_check(t_game *game);

/*
	key.c
*/
int		clear_game(t_game *game);
void	move_w(t_game *g);
void	move_a(t_game *g);
void	move_s(t_game *g);
void	move_d(t_game *g);

/*
	so_long.c
*/
void	print_err(char *message);
void	game_init(t_game *g, char *map);
int		exit_game(t_game *game);
int		press_key(int key_code, t_game *game);
int		main(int ac, char *av[]);

#endif
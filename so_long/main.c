#include "so_long.h"

int is_valid_arg(int argc, char *argv);
void	game_init(t_game *g, char *map);

void	print_err(char *message);
int	exit_game(t_game *game);
int	press_key(int key_code, t_game *game);

//extern int가 모얌?
//저게 있으면 main 함수 return(0)이 없어도 되는건가?
int	main(int argc, char *argv[])
{
	t_game	*game;

    if (!is_valid_arg(argc, argv[1]))
        return (0);
	game = malloc(sizeof(t_game));
    if (!game)
        return (0); //그냥 리턴 해도됨?
	game_init(game, argv[1]);
	mlx_hook(game->win, KEY_PRESS, 0, &key_hook, game);//press_key (hook 이 뭐지?)
	mlx_hook(game->win, KEY_EXIT, 0, &exit_game, game);
	mlx_loop(game->mlx);
	return (0);
}

int is_valid_arg(int argc, char *argv)
{
    if (argc != 2)
        ft_pstr_exit("Map is missing.\n");
    else if (ft_strlen(filename) < 5 || \
    (ft_strrchr(filename, '.') && ft_strncmp(ft_strrchr(filename, '.'), ".ber", 5))))
        ft_pstr_exit("Error\n: Argument must be like ./so_long *.ber");
    else
        return 1;
}

void	game_init(t_game *game, char *filename)
{
    map_init(game, filename);
	game->mlx = mlx_init();
    if (!game->mlx)
        ft_pstr_exit("Error\n: mlx_init() failed..");
	game->win = mlx_new_window(game->mlx, game->wid * 64, game->hei * 64, "so_long");
    if (!gmae->win)
        ft_pstr_exit("Error\n: mlx_new_window() failed..");
	game->img = img_init(game);//xpm_file_to_image
    setting_img(game);//put_image_to_window(_all)
}

void	print_err(char *message)
{
	write(2, "Error\n", 6);
	write(2, message, ft_strlen(message));
	exit(1);
}

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int	press_key(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		exit_game(game);
	if (key_code == KEY_W)
		move_w(game);
	if (key_code == KEY_A)
		move_a(game);
	if (key_code == KEY_S)
		move_s(game);
	if (key_code == KEY_D)
		move_d(game);
	return (0);
}
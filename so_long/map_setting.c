/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:12:30 by sumjang           #+#    #+#             */
/*   Updated: 2022/07/13 15:12:31 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    map_init(t_game *gmae, char *filename);
void    read_map(t_game *game, char *filename);
void    is_valid_map(t_game *game);
void    composed_char(t_game *game, int x, int y);

void    map_init(t_game *game, char *filename)
{
    int i = 0;

    read_map(game, filename);
    game->y = ft_strlen(game->map[0]);
    i = 0;
    while (game->map[i])
        i++;
    game->x = i;
    game->movement = 0;//bonus?
    is_valid_map(game);
}

void    read_map(t_game *game, char *filename)
{
    int     fd;
    char    *line;
    char    *lines;
    char    *tmp;

    fd = open(filename, O_RDONLY);
    if (fd <= 0) // 이거 훼이크임? (fd != 1) 혹은 (fd == -1)
        print_err("File open fail.\n"); //error 출력 수정
    while (1)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break;
        tmp = lines;
        lines = ft_strjoin(lines, line);
        free(line);
        free(tmp);
    }
    if (lines == NULL)
        ft_pstr_exit("Error\n: Map is empty.."); //error 수정
    game->map = ft_split(lines, '\n');
    free(lines);
    if (!close(fd))
        ft_perror_exit("Error\n"); // close 이런 함수들 오류에는 ft_perror 인가?
}

void    is_valid_map(t_game *game)
{
    int x;
    int y;

    x = 0;
    while (x < game->x)
    {
        y = 0;
        while (y < game -> y)
        {
            if (game->map[x][y] != '1' && \
            (x == 0 || x == game->x - 1 || y == 0 || y == game->y - 1))
                ft_pstr_exit("Error\n: Map must be surrounded by wall.."); //error + closed/surrounded ?map valid 확인 철저하게 해야할듯. 구멍나있는지, 혹은 더 많은지, 중간에 비었는지 등
            if (y == game->y - 1 && game->map[x][y + 1] != NULL)
                ft_pstr_exit("Error\n: Map must be rectangular.."); //error
            composed_char(game, x, y);
            y++;
        }
        x++;
    }
    if (game->collectible < 1 || game->exit < 1 || game->player != 1)//player?
        ft_pstr_exit("Error\n: Map must have\
        at least 1 exit, 1 collectible, and 1 starting position..");//error
}

void    composed_char(t_game *game, int x, int y)
{
    char    c;

    c = game->map[x][y];
    if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
        ft_pstr_exit("Error\n: Map must be composed of 5 possible characters..");//error
    if (c == 'C')
        game->collectible++;
    else if (c == 'E')
        game->exit++;//bonus
    else if (c == 'P')//bonus 혹은 시작위치때문에?
    {
        game->player++;


    }
}

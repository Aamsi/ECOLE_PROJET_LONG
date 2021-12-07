#include "mlx.h"
#include "so_long.h"
#include <unistd.h>


void    add_img(t_img *dst, t_img *src, int x_start, int y_start) {
    t_coord dst_pos;
    t_coord src_pos;
    char    *addr_dst;
    char    *addr_src;

    dst_pos.y = y_start;
    src_pos.y = 0;
    while (dst_pos.y < y_start + 32)
    {
        dst_pos.x = x_start;
        src_pos.x = 0;
        while (dst_pos.x < x_start + 32)
        {
            addr_dst = dst->addr + (dst_pos.y * dst->width + dst_pos.x * 4);
            addr_src = src->addr + (src_pos.y * src->width + src_pos.x * 4);
            if ((int)*addr_dst != (int)*addr_src && (int)*addr_src != 0)
                ft_memcpy(addr_dst, addr_src, 4);

            dst_pos.x++;
            src_pos.x++;
        }
        dst_pos.y++;
        src_pos.y++;
    }
}

void    draw_map(t_game *game)
{
    int     i;
    int     j;

    i = 0;
    j = 0;
    while(game->map[i])
    {
        j = 0;
        while(game->map[i][j])
        {
            add_img(&game->screen, &game->grass, j * 32, i * 32);
            if (game->map[i][j] == '1')
                add_img(&game->screen, &game->walls, j * 32, i * 32);
            else if (game->map[i][j] == 'C')
                add_img(&game->screen, &game->collectible, j * 32, i * 32);
            else if (game->map[i][j] == 'E')
                add_img(&game->screen, &game->exit, j * 32, i * 32);
            j++;
        }
        i++;
    }
    add_img(&game->screen, &game->character, game->character_x * 32, game->character_y * 32);
    mlx_put_image_to_window(game->mlx, game->mlx_win, game->screen.img, 0, 0);
}

char    **add_map(char *line, char **tab)
{
    char    **new_tab;
    int     i;

    i = 0;
    while(tab && tab[i])
        i++;
    new_tab = malloc(sizeof(char *) * (i + 2));
    if (!new_tab)
        return NULL;
    new_tab[i + 1] = NULL;
    new_tab[i] = line;
    while (i-- > 0)
        new_tab[i] = tab[i];
    free(tab);
    return (new_tab);
}

char     **parse_map(char *file, t_game *game)
{
    char        *line;
    int         fd;
    int         ret;

    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (NULL);
    ret = 1;
    while (ret > 0)
    {
        ret = get_next_line(fd, &line);
        if (ret < 0)
            return (NULL);
        game->map = add_map(line, game->map);
        game->height++;
        if (ret == 0)
        {
            game->width = ft_strlen(line) * 32;
            break;
        }
    }
    game->height *= 32;
    return (game->map);
}

int         check_walls(char **map, t_game *game)
{
    int width;
    int height;
    int j;

    width = game->width / 32 - 1;
    height = game->height / 32 - 1;

    j = 0;
    while (map[0][j])
    {
        if (map[0][j] != '1')
            return (0);
        j++;
    }
    j = 0;
    while (map[height][j])
    {
        if (map[height][j] != '1')
            return (0);
        j++;
    }
    j = 0;
    while (map[j])
    {
        if (map[j][0] != '1' || map[j][width] != '1')
            return (0);
        j++;
    }
    return (1);
}

int     check_exit_collectible_start(char **map, t_game *game)
{
    int i;
    int j;
    int exit;
    int collectible;
    int start;

    i = 0;
    exit = 0;
    collectible = 0;
    start = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'E')
                exit = 1;
            if (map[i][j] == 'C')
                collectible = 1;
            if (map[i][j] == 'P')
            {
                game->character_x = j;
                game->character_y = i;
                start = 1;
            }
            if (exit && collectible && start)
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int check_rectangle(char **map)
{
    int i;

    i = 1;
    while (map[i])
    {
        if (ft_strlen(map[i]) != ft_strlen(map[i - 1]))
            return (0);
        i++;
    }
    return (1);
}

int check_map(char **map, t_game *game)
{
    if (!(check_walls(map, game)))
        return (0);
    if (!(check_exit_collectible_start(map, game)))
        return (0);
    if (!(check_rectangle(map)))
        return (0);
    return (1);
}
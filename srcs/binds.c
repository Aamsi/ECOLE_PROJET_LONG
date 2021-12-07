#include "mlx.h"
#include "so_long.h"
#include <unistd.h>


int close_window(t_game *game)
{
    mlx_destroy_window(game->mlx, game->mlx_win);
    exit(EXIT_SUCCESS);
    return EXIT_SUCCESS;
}

int move_up(t_game *game)
{
    game->character_y -= 1;
    return 1;
}

int move_down(t_game *game)
{
    game->character_y += 1;
    return 1;
}

int move_left(t_game *game)
{
    game->character_x -= 1;
    return 1;
}

int move_right(t_game *game)
{
    game->character_x += 1;
    return 1;
}

int binds(int keycode, t_game *game)
{
    if (keycode == 65307)
        return close_window(game);
    if (keycode == 119)
        return move_up(game);
    if (keycode == 115)
        return move_down(game);
    if (keycode == 97)
        return move_left(game);
    if (keycode == 100)
        return move_right(game);

    return game->height;
}

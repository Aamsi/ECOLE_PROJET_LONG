#include "mlx.h"
#include "so_long.h"
#include <stdio.h>

// gcc -o test main.c -Lminilibx-linux -lmlx -lm -lbsd -lX11 -lXext

int render_next_frame(t_game *game)
{
    draw_map(game);
    return (1);
}

int main(int argc, char **argv)
{
    t_game  game;

    if (argc != 2)
    {
        printf("Mauvais arguments.\n");
        return (-1);
    }
    init_struct(&game);
    parse_map(argv[1], &game);
    if (!check_map(game.map, &game))
    {
        free_map(&game);
        return (-1);
    }
    if (!(init_game(&game)))
    {
        free_for_all_long(&game);
        return (-1);
    }
    mlx_hook(game.mlx_win, 2, 1L<<0, binds, &game);
    mlx_loop_hook(game.mlx, render_next_frame, &game);
    mlx_loop(game.mlx);
    free_for_all_long(&game);
}
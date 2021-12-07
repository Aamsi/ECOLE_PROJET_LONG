#include "mlx.h"
#include "so_long.h"
#include <stdio.h>

// gcc -o test main.c -Lminilibx-linux -lmlx -lm -lbsd -lX11 -lXext

int render_next_frame(t_game *game)
{
    draw_map(game);
    return 1;
}

int main(void)
{
    t_game  game;
    int res_width;
    int res_height;

    init_struct(&game);

    parse_map("maps/map_big_maze.ber", &game);
    if (!check_map(game.map, &game)) {
        printf("Error\n");
        return (-1);
    }

    game.mlx = mlx_init();
    game.mlx_win = mlx_new_window(game.mlx, game.width, game.height, "So long");
    mlx_get_screen_size(game.mlx, &res_width, &res_height);
    if (game.width > res_width || game.height > res_height)
    {
        printf("Error, la map est trop grande pour la resolution de cet ecran.\n");
        return (-1);
    }
    game.screen.img = mlx_new_image(game.mlx, game.width, game.height);
    game.screen.addr = mlx_get_data_addr(game.screen.img, &game.screen.height, &game.screen.width, &game.screen.endian);

    game.character.img = mlx_xpm_file_to_image(game.mlx, "./fixtures/character.xpm", &game.character.width, &game.character.height);
    game.character.addr = mlx_get_data_addr(game.character.img, &game.character.height, &game.character.width, &game.character.endian);

    game.walls.img = mlx_xpm_file_to_image(game.mlx, "./fixtures/wall.xpm", &game.walls.width, &game.walls.height);
    game.walls.addr = mlx_get_data_addr(game.walls.img, &game.walls.height, &game.walls.width, &game.walls.endian);

    game.grass.img = mlx_xpm_file_to_image(game.mlx, "./fixtures/grass.xpm", &game.grass.width, &game.grass.height);
    game.grass.addr = mlx_get_data_addr(game.grass.img, &game.grass.height, &game.grass.width, &game.grass.endian);

    game.exit.img = mlx_xpm_file_to_image(game.mlx, "./fixtures/exit.xpm", &game.exit.width, &game.exit.height);
    game.exit.addr = mlx_get_data_addr(game.exit.img, &game.exit.height, &game.exit.width, &game.exit.endian);

    game.collectible.img = mlx_xpm_file_to_image(game.mlx, "./fixtures/collectible.xpm", &game.collectible.width, &game.collectible.height);
    game.collectible.addr = mlx_get_data_addr(game.collectible.img, &game.collectible.height, &game.collectible.width, &game.collectible.endian);

    mlx_hook(game.mlx_win, 2, 1L<<0, binds, &game);
    mlx_loop_hook(game.mlx, render_next_frame, &game);
    mlx_loop(game.mlx);
}
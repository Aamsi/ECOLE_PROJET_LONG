#include "mlx.h"
#include "so_long.h"
#include <unistd.h>


int check_next_step(int x, int y, char **map)
{
    int i;
    int j;

    i = 0;
    while(map[i])
    {
        j = 0;
        while(map[i][j])
        {
            if (map[i][j] == '1' && x == j && y == i)
                return (1);
            if (map[i][j] == 'C' && x == j && y == i)
                return (2);
            if (map[i][j] == 'E' && x == j && y == i)
                return (3);
            j++;
        }
        i++;
    }
    return (0);
}

int close_window(t_game *game)
{
    mlx_destroy_window(game->mlx, game->mlx_win);
    exit(EXIT_SUCCESS);
    return EXIT_SUCCESS;
}

int finish_game(t_game *game)
{
    int i;
    int j;

    i = 0;
    while(game->map[i])
    {
        j = 0;
        while(game->map[i][j])
        {
            if (game->map[i][j] == 'C')
            {
                printf("Vous n'avez pas collecté tous les collectibles, vous ne pouvez pas partir.\n");
                return (0);
            }
            j++;
        }
        i++;
    }
    printf("Félicitations, vous avez terminé le jeu en %d mouvements.\n", game->moves);
    return close_window(game);
}

int move_up(t_game *game)
{
    int can_move;

    can_move = check_next_step(game->character_x, game->character_y - 1, game->map);
    if (can_move == 1)
        return (0);
    game->character_y -= 1;
    game->moves += 1;
    printf("Vous avez utilisé %d mouvement(s).\n", game->moves);
    if (can_move == 2)
        game->map[game->character_y][game->character_x] = '0';
    if (can_move == 3)
        finish_game(game);
    return 1;
}

int move_down(t_game *game)
{
    int can_move;

    can_move = check_next_step(game->character_x, game->character_y + 1, game->map);
    if (can_move == 1)
        return (0);
    game->character_y += 1;
    game->moves += 1;
    printf("Vous avez utilisé %d mouvement(s).\n", game->moves);
    if (can_move == 2)
        game->map[game->character_y][game->character_x] = '0';
    if (can_move == 3)
        finish_game(game);
    return 1;
}

int move_left(t_game *game)
{
    int can_move;

    can_move = check_next_step(game->character_x - 1, game->character_y, game->map);
    if (can_move == 1)
        return (0);
    game->character_x -= 1;
    game->moves += 1;
    printf("Vous avez utilisé %d mouvement(s).\n", game->moves);
    if (can_move == 2)
        game->map[game->character_y][game->character_x] = '0';
    if (can_move == 3)
        finish_game(game);
    return 1;
}

int move_right(t_game *game)
{
    int can_move;

    can_move = check_next_step(game->character_x + 1, game->character_y, game->map);
    if (can_move == 1)
        return (0);
    game->character_x += 1;
    game->moves += 1;
    printf("Vous avez utilisé %d mouvement(s).\n", game->moves);
    if (can_move == 2)
        game->map[game->character_y][game->character_x] = '0';
    if (can_move == 3)
        finish_game(game);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binds.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:51:50 by iouali            #+#    #+#             */
/*   Updated: 2021/12/13 18:51:55 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include <unistd.h>

int	move_up(t_game *game)
{
	int	can_move;

	can_move = check_next_step(game->character_x, game->character_y - 1,
			game->map);
	if (can_move == 1)
		return (0);
	game->character_y -= 1;
	game->moves += 1;
	printf("Vous avez utilisé %d mouvement(s).\n", game->moves);
	if (can_move == 2)
		game->map[game->character_y][game->character_x] = '0';
	if (can_move == 3)
		finish_game(game);
	return (1);
}

int	move_down(t_game *game)
{
	int	can_move;

	can_move = check_next_step(game->character_x, game->character_y + 1,
			game->map);
	if (can_move == 1)
		return (0);
	game->character_y += 1;
	game->moves += 1;
	printf("Vous avez utilisé %d mouvement(s).\n", game->moves);
	if (can_move == 2)
		game->map[game->character_y][game->character_x] = '0';
	if (can_move == 3)
		finish_game(game);
	return (1);
}

int	move_left(t_game *game)
{
	int	can_move;

	can_move = check_next_step(game->character_x - 1, game->character_y,
			game->map);
	if (can_move == 1)
		return (0);
	game->character_x -= 1;
	game->moves += 1;
	printf("Vous avez utilisé %d mouvement(s).\n", game->moves);
	if (can_move == 2)
		game->map[game->character_y][game->character_x] = '0';
	if (can_move == 3)
		finish_game(game);
	return (1);
}

int	move_right(t_game *game)
{
	int	can_move;

	can_move = check_next_step(game->character_x + 1, game->character_y,
			game->map);
	if (can_move == 1)
		return (0);
	game->character_x += 1;
	game->moves += 1;
	printf("Vous avez utilisé %d mouvement(s).\n", game->moves);
	if (can_move == 2)
		game->map[game->character_y][game->character_x] = '0';
	if (can_move == 3)
		finish_game(game);
	return (1);
}

int	binds(int keycode, t_game *game)
{
	if (keycode == 65307)
		return (close_window(game));
	if (keycode == 119)
		return (move_up(game));
	if (keycode == 115)
		return (move_down(game));
	if (keycode == 97)
		return (move_left(game));
	if (keycode == 100)
		return (move_right(game));
	return (game->height);
}

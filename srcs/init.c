/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:06:03 by iouali            #+#    #+#             */
/*   Updated: 2021/12/13 19:27:07 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	init_struct(t_game *game)
{
	game->map = 0;
	game->height = 0;
	game->width = 0;
	game->moves = 0;
}

int	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, game->width, game->height,
			"So long");
	game->screen.img = mlx_new_image(game->mlx, game->width, game->height);
	game->screen.addr = mlx_get_data_addr(game->screen.img,
			&game->screen.height, &game->screen.width,
			&game->screen.endian);
	game->character.img = mlx_xpm_file_to_image(game->mlx,
			"./fixtures/character.xpm", &game->character.width,
			&game->character.height);
	game->character.addr = mlx_get_data_addr(game->character.img,
			&game->character.height, &game->character.width,
			&game->character.endian);
	game->walls.img = mlx_xpm_file_to_image(game->mlx,
			"./fixtures/wall.xpm", &game->walls.width,
			&game->walls.height);
	game->walls.addr = mlx_get_data_addr(game->walls.img,
			&game->walls.height, &game->walls.width, &game->walls.endian);
	return (init_game_bis(game));
}

int	init_game_bis(t_game *game)
{
	int	res_width;
	int	res_height;

	game->grass.img = mlx_xpm_file_to_image(game->mlx,
			"./fixtures/grass.xpm", &game->grass.width,
			&game->grass.height);
	game->grass.addr = mlx_get_data_addr(game->grass.img,
			&game->grass.height, &game->grass.width, &game->grass.endian);
	game->exit.img = mlx_xpm_file_to_image(game->mlx,
			"./fixtures/exit.xpm", &game->exit.width, &game->exit.height);
	game->exit.addr = mlx_get_data_addr(game->exit.img,
			&game->exit.height, &game->exit.width, &game->exit.endian);
	game->collectible.img = mlx_xpm_file_to_image(game->mlx,
			"./fixtures/collectible.xpm", &game->collectible.width,
			&game->collectible.height);
	game->collectible.addr = mlx_get_data_addr(game->collectible.img,
			&game->collectible.height, &game->collectible.width,
			&game->collectible.endian);
	mlx_get_screen_size(game->mlx, &res_width, &res_height);
	if (game->width > res_width || game->height > res_height)
		return (return_errors("La map est trop grande pour la \
resolution de cet ecran"));
	return (1);
}

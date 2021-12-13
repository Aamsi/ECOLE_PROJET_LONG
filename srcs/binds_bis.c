/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binds_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:52:01 by iouali            #+#    #+#             */
/*   Updated: 2021/12/13 18:52:02 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include <unistd.h>

int	check_next_step(int x, int y, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
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

int	close_window(t_game *game)
{
	return (mlx_loop_end(game->mlx));
}

int	finish_game(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
			{
				printf("Vous n'avez pas collecté tous les collectibles,\
 vous ne pouvez pas partir.\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	printf("Félicitations, vous avez terminé le jeu en\
 %d mouvements.\n", game->moves);
	return (mlx_loop_end(game->mlx));
}

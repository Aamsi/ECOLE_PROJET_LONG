/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:04:15 by iouali            #+#    #+#             */
/*   Updated: 2021/12/13 19:05:41 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include <unistd.h>

int	check_walls(char **map, t_game *game)
{
	int	width;
	int	height;
	int	j;

	width = game->width / 32 - 1;
	height = game->height / 32 - 1;
	j = 0;
	while (map[0][j])
	{
		if (map[0][j] != '1' || map[height][j] != '1')
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

int	check_exit_collectible_start(t_game *game)
{
	int	exit;
	int	collectible;
	int	start;

	exit = 0;
	collectible = 0;
	start = 0;
	return (check_loop(game, collectible, exit, start));
}

int	check_loop(t_game *game, int collectible, int exit, int start)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'E')
				exit = 1;
			if (game->map[i][j] == 'C')
				collectible = 1;
			if (game->map[i][j] == 'P')
			{
				game->character_x = j;
				game->character_y = i;
				start = 1;
			}
			if (exit && collectible && start)
				return (1);
			j++;
		}
	}
	return (0);
}

int	check_rectangle(char **map)
{
	int	i;

	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[i - 1]))
			return (0);
		i++;
	}
	return (1);
}

int	check_charac(char **map)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			c = map[i][j];
			if (c != 'P' && c != 'C' && c != '0' && c != '1' && c != 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

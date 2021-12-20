/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:52:08 by iouali            #+#    #+#             */
/*   Updated: 2021/12/20 17:17:00 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include <stdio.h>

int	return_errors(char *str)
{
	printf("Error: %s\n", str);
	return (0);
}

void	*free_map(t_game *game)
{
	int	i;

	if (!(game->map))
		return (NULL);
	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	return (NULL);
}

int	free_for_all_long(t_game *game)
{
	if (game->screen.img)
		mlx_destroy_image(game->mlx, game->screen.img);
	if (game->character.img)
		mlx_destroy_image(game->mlx, game->character.img);
	if (game->walls.img)
		mlx_destroy_image(game->mlx, game->walls.img);
	if (game->grass.img)
		mlx_destroy_image(game->mlx, game->grass.img);
	if (game->collectible.img)
		mlx_destroy_image(game->mlx, game->collectible.img);
	if (game->exit.img)
		mlx_destroy_image(game->mlx, game->exit.img);
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free_map(game);
	return (1);
}

int	check_extension(char *file)
{
	char	*file_extension;
	int		extension_len;

	file_extension = ft_strrchr(file, '.');
	extension_len = ft_strlen(file_extension);
	if (ft_strncmp(".ber", file_extension, extension_len) != 0)
		return (-1);
	return (0);
}

int	check_line_empty(char *line)
{
	if (line[0] == 0)
	{
		free(line);
		return (0);
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:53:11 by iouali            #+#    #+#             */
/*   Updated: 2021/12/20 17:22:16 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include <unistd.h>

void	add_img(t_img *dst, t_img *src, int x_start, int y_start)
{
	t_coord	dst_pos;
	t_coord	src_pos;
	char	*addr_dst;
	char	*addr_src;

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

void	draw_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
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
	add_img(&game->screen, &game->character, game->character_x * 32,
		game->character_y * 32);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->screen.img, 0, 0);
}

char	**add_map(char *line, char **tab)
{
	char	**new_tab;
	int		i;

	i = 0;
	while (tab && tab[i])
		i++;
	new_tab = malloc(sizeof(char *) * (i + 2));
	if (!new_tab)
		return (NULL);
	new_tab[i + 1] = NULL;
	new_tab[i] = line;
	while (i-- > 0)
		new_tab[i] = tab[i];
	free(tab);
	return (new_tab);
}

char	**parse_map(char *file, t_game *game)
{
	char	*line;
	int		fd;
	int		ret;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (ret < 0)
			return (NULL);
		if (check_line_empty(line) == 0)
			break ;
		game->map = add_map(line, game->map);
		game->height++;
		game->width = ft_strlen(line) * 32;
		if (ret == 0)
			break ;
	}
	game->height *= 32;
	return (game->map);
}

int	check_map(char **map, t_game *game)
{
	if (game->height == 0)
		return (return_errors("La map est vide ou le fichier \
n'a pas été trouvé."));
	if (!(check_charac(map)))
		return (return_errors("Il y a des charactères \
non-autorisés dans la map."));
	if (!(check_walls(map, game)))
		return (return_errors("Les murs sont peut-être mal agencés."));
	if (!(check_exit_collectible_start(game)))
		return (return_errors("Il n'y a pas d'exit, \
ou de collectibles, ou de spawn."));
	if (!(check_rectangle(map)))
		return (return_errors("La map n'est pas un rectangle."));
	return (1);
}

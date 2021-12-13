/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:13:02 by iouali            #+#    #+#             */
/*   Updated: 2021/12/13 19:13:30 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*
** get_next_line
*/

# include "get_next_line.h"

/*
** parse_map
*/

# include "so_long_struc.h"

# include "libft.h"

char	**parse_map(char *file, t_game *game);
void	draw_map(t_game *game);
void	init_struct(t_game *game);
int		init_game(t_game *game);
int		check_map(char **map, t_game *game);
int		binds(int keycode, t_game *game);
void	add_img(t_img *dst, t_img *src, int x_start, int y_start);
int		return_errors(char *str);
int		free_for_all_long(t_game *game);
void	*free_map(t_game *game);
int		check_next_step(int x, int y, char **map);
int		close_window(t_game *game);
int		finish_game(t_game *game);
int		check_walls(char **map, t_game *game);
int		check_exit_collectible_start(t_game *game);
int		check_rectangle(char **map);
int		check_charac(char **map);
int		check_map(char **map, t_game *game);
int		check_loop(t_game *game, int collectible, int exit, int start);
int		init_game_bis(t_game *game);

#endif

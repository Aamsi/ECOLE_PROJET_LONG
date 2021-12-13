/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_struc.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:13:54 by iouali            #+#    #+#             */
/*   Updated: 2021/12/13 19:16:29 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_STRUC_H
# define SO_LONG_STRUC_H

typedef struct s_img {
	void	*img;
	char	*addr;
	int		height;
	int		width;
	int		endian;
}				t_img;

typedef struct s_game {
	void	*mlx;
	void	*mlx_win;
	t_img	screen;
	t_img	character;
	t_img	walls;
	t_img	grass;
	t_img	collectible;
	t_img	exit;
	char	**map;
	int		height;
	int		width;
	int		character_x;
	int		character_y;
	int		moves;
}				t_game;

typedef struct s_coord {
	int	x;
	int	y;
}				t_coord;

#endif
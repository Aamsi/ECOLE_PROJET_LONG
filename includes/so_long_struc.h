#ifndef SO_LONG_STRUC_H
# define SO_LONG_STRUC_H

typedef struct s_map {
    char *map_char;
}               t_map;

typedef struct	s_img {
	void    *img;
	char	*addr;
	int		height;
	int		width;
	int     endian;
}				t_img;

typedef struct s_game {
    void    *mlx;
    void    *mlx_win;
    t_img   screen;
    t_img   character;
    t_img   walls;
    t_img   grass;
    t_img   collectible;
    char    **map;
    int     height;
    int     width;
    int     character_x;
    int     character_y;
}               t_game;

typedef struct s_coord {
    int x;
    int y;
}               t_coord;

typedef struct s_parsing {
    int one_exit;
    int one_collectible;
    int one_start;
    int rectangular;
    int walls;
}               t_parsing;

#endif
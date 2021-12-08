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

char    **parse_map(char *file, t_game *game);
void    draw_map(t_game *game);
void    init_struct(t_game *game);
int    init_game(t_game *game);
int     check_map(char **map, t_game *game);
int     binds(int keycode, t_game *game);
void    add_img(t_img *dst, t_img *src, int x_start, int y_start);
int     return_errors(char *str);
int     free_for_all_long(t_game *game);
void    *free_map(t_game *game);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 10:53:20 by iouali            #+#    #+#             */
/*   Updated: 2021/08/16 15:05:54 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int			get_next_line(int fd, char **line);
char		*ft_strndup(char *s, size_t size);
char		*delete_former_str(char *s, char c);
int			read_file(int fd, char **tmp_char);
int			free_for_all(char *tmp_char);

#endif

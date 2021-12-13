/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 10:44:48 by iouali            #+#    #+#             */
/*   Updated: 2021/12/13 19:02:45 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	read_file(int fd, char **tmp_char)
{
	char	buff[100 + 1];
	int		ret;

	ret = 1;
	while (!ft_strchr(*tmp_char, '\n') && ret > 0)
	{
		ret = read(fd, buff, 100);
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';
		if (*tmp_char == 0)
		{
			*tmp_char = ft_strdup(buff);
			if (!(*tmp_char))
				return (-1);
		}
		else
		{
			*tmp_char = ft_strjoin(*tmp_char, buff);
			if (!*tmp_char)
				return (-1);
		}
	}
	return (ret);
}

int	ft_strlen_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	return (i);
}

int	get_next_line(int fd, char **line)
{
	static char		*tmp_char[256];
	int				ret;

	if (!line || 100 <= 0 || fd < 0 || fd > 256)
		return (-1);
	ret = read_file(fd, &tmp_char[fd]);
	if (ret == -1)
		return (free_for_all(tmp_char[fd]));
	*line = ft_strndup(tmp_char[fd], ft_strlen_nl(tmp_char[fd]));
	if (!(*line))
		return (free_for_all(tmp_char[fd]));
	tmp_char[fd] = delete_former_str(tmp_char[fd], '\n');
	if (!(tmp_char[fd]))
		return (free_for_all(tmp_char[fd]));
	if (ret == 0)
	{
		free(tmp_char[fd]);
		tmp_char[fd] = NULL;
		return (0);
	}
	return (1);
}

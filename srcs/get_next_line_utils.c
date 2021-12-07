/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 10:53:17 by iouali            #+#    #+#             */
/*   Updated: 2021/08/16 15:05:25 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strndup(char *s, size_t size)
{
	size_t	i;
	char	*result;

	result = malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < size)
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*delete_former_str(char *s, char c)
{
	int		i;
	char	*new_str;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	if (s[i] == c)
		i++;
	new_str = ft_strdup(s + i);
	free(s);
	return (new_str);
}

int		free_for_all(char *tmp_char)
{
	if (tmp_char)
	{
		free(tmp_char);
		tmp_char = NULL;
	}
	return (-1);
}

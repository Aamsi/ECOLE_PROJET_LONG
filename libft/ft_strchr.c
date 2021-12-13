/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 09:35:18 by iouali            #+#    #+#             */
/*   Updated: 2021/08/16 15:15:23 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *s, int c)
{
	int		i;
	int		len;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	while (i < len + 1)
	{
		if (s[i] == (unsigned char)c)
			return (s + i);
		i++;
	}
	return (NULL);
}

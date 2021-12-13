/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 11:54:20 by iouali            #+#    #+#             */
/*   Updated: 2021/12/13 19:24:17 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;
	char	*tmp_s;

	str = malloc(sizeof(char) * len + 1);
	if (!(str))
		return (NULL);
	if (!s || start >= ft_strlen(s))
		return (str);
	tmp_s = (char *)s;
	i = 0;
	while (i < len && tmp_s[start])
	{
		str[i] = tmp_s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

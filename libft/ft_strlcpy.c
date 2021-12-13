/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 10:14:50 by iouali            #+#    #+#             */
/*   Updated: 2021/08/16 15:18:39 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t			i;
	unsigned int	len;
	unsigned char	*tmp_src;

	if (!dest && !src)
		return (0);
	tmp_src = (unsigned char *)src;
	i = 0;
	while ((tmp_src[i]) && i + 1 < size)
	{
		dest[i] = tmp_src[i];
		i++;
	}
	if (size > 0)
		dest[i] = '\0';
	len = 0;
	while (tmp_src[len])
		len++;
	return (len);
}

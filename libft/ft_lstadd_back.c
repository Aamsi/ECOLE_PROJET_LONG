/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:23:39 by iouali            #+#    #+#             */
/*   Updated: 2021/12/13 19:22:24 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*lst;

	if (!new)
		return ;
	if (*alst)
	{
		lst = ft_lstlast(*alst);
		lst->next = new;
	}
	else
		ft_lstadd_front(alst, new);
}

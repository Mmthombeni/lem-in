/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmthombe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 18:17:43 by mmthombe          #+#    #+#             */
/*   Updated: 2017/12/20 18:26:05 by mmthombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_list_push(t_list **begin, void *data)
{
	t_list *node;
	t_list *trav;

	node = ft_create_node(data);
	if (!*begin)
		*begin = node;
	else
	{
		trav = *begin;
		while (trav->next)
			trav = trav->next;
		trav->next = node;
	}
	return (node);
}

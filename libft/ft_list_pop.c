/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_pop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmthombe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 17:21:31 by mmthombe          #+#    #+#             */
/*   Updated: 2017/12/20 12:04:25 by mmthombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	remove_element(t_list **list, t_list *cursor)
{
	if (cursor == *list)
		*list = NULL;
	free(cursor);
	cursor = NULL;
}

void	*ft_list_pop(t_list **list)
{
	t_list *last_ele;
	t_list *cursor;
	void	*data;

	cursor = *list;
	last_ele = NULL;
	while (cursor)
	{
		if (cursor->next)
		{
			if (cursor->next->next == NULL)
				last_ele = cursor;
		}
		else
		{
			data = cursor->data;
			if (last_ele)
				last_ele->next = NULL;
			remove_element(list, cursor);
			return (data);
		}
	cursor = cursor->next;
	}
	return (NULL);
}

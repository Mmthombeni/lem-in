/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmthombe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 18:25:41 by mmthombe          #+#    #+#             */
/*   Updated: 2017/12/19 18:28:46 by mmthombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_create_node(void *data)
{
	t_list *element;

	element = malloc(sizeof(t_list));
	if (element)
	{
		element->data = data;
		element->next = NULL;
	}
	return (element);
}

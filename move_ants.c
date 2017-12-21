/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmthombe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 04:09:46 by mmthombe          #+#    #+#             */
/*   Updated: 2017/12/20 13:23:58 by mmthombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	from_room(t_room *room, t_room *min_room, t_list **list)
{
	if (room->numants > 0)
	{
		if (room->type == START)
			ants_from_start(room, list);
		else if (contains(*list, room) == 0)
			move_ant(room, min_room, list);
	}
}

int		min_val(int min, t_room *adj, t_room **min_room)
{
	int	dist;

	dist = short_dist(adj, 0);
	if (dist < min)
	{
		*min_room = adj;
		return (dist);
	}
	return (min);
}

void	move_ants(t_room *room, t_list **list)
{
	t_list			*adj_rooms;
	t_room			*adj;
	t_room			*min_room;
	static t_list	*v_rooms = NULL;
	int				min;

	adj_rooms = room->adj_rooms;
	min = MAX_INT;
	ft_list_push(&v_rooms, room);
	while (adj_rooms)
	{
		adj = (t_room *)adj_rooms->data;
		if (contains(v_rooms, adj) == 0 && adj->type != END)
			move_ants(adj, list);
		min = min_val(min, adj, &min_room);
		adj_rooms = adj_rooms->next;
	}
	from_room(room, min_room, list);
	ft_list_pop(&v_rooms);
}

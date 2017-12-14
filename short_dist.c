

#include "lemin.h"

int		contains(t_list *rooms, t_room *room)
{
	t_room *rm;
	t_list *iter;

	iter = rooms;
	while (iter)
	{
		rm = (t_room *)iter->data;
		if (ft_strcmp(rm->name, room->name) == 0)
			return (1);
		iter = iter->next;
	}
	return (0);
}

int		short_dist(t_room *room, int dist)
{
	t_list			*adj_rooms;
	static t_list	*v_rooms = NULL;
	t_room			*rm;
	int				rm_dist;
	int				min;

	if (room->type == END)
		return (dist);
	adj_rooms = room->adj_rooms;
	min = MAX_INT;
	ft_list_push_back(&v_rooms, room);
	while (adj_rooms)
	{
		rm = (t_room *)adj_rooms->data;
		if (contains(v_rooms, rm) == 0 && rm->type != START)
		{
			rm_dist = short_dist(rm, dist + 1);
			if (rm_dist < min)
				min = rm_dist;
		}
		adj_rooms = adj_rooms->next;
	}
	ft_list_pop(&v_rooms);
	return (min);
}

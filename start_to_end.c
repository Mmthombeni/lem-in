
#include "lemin.h"

t_room	*get_room(t_list *rooms, t_type type)
{
	t_room *room;

	while (rooms)
	{
		room = (t_room *)rooms->data;
		if (room->type == type)
			return (room);
		rooms = rooms->next;
	}
	return (NULL);
}

void	putmove(unsigned int ant, char *name)
{
	ft_putchar('L');
	ft_putnbr(ant);
	ft_putchar('-');
	ft_putstr(name);
	ft_putchar(' ');
}

void	move_ant(t_room *from, t_room *to, t_list **ants)
{
	if (to->type == END || (to->type == ROOM && to->numants == 0))
	{
		from->numants--;
		to->numants++;
		if (from->type == START)
		{
			from->ant++;
			putmove(from->ant, to->name);
			to->ant = from->ant;
		}
		else
		{
			putmove(from->ant, to->name);
			to->ant = from->ant;
			ft_list_push_back(ants, to);
			from->ant = 0;
		}
	}
}

void	ants_from_start(t_room *start, t_list **list)
{
	t_list			*iter;
	t_room			*room;
	unsigned int	min_dist;
	unsigned int	dist;

	iter = start->adj_rooms;
	min_dist = MAX_INT;
	while (iter)
	{
		room = (t_room *)iter->data;
		dist = short_dist(room, 0);
		if (dist < min_dist)
			min_dist = dist;
		iter = iter->next;
	}
	iter = start->adj_rooms;
	while (iter)
	{
		room = (t_room *)iter->data;
		dist = short_dist(room, 0);
		if (dist - min_dist <= start->numants && start->numants > 0)
			move_ant(start, room, list);
		iter = iter->next;
	}
}

void	start_to_end(t_farm *farm)
{
	t_room *start;
	t_room *end;
	t_list *ants_moved;
	t_list *exp_rooms;

	if (error(farm, 0))
		return ;
	start = get_room(farm->rooms, START);
	end = get_room(farm->rooms, END);
	ants_moved = NULL;
	exp_rooms = NULL;
	verify_path(start, &exp_rooms);
	if (contains(exp_rooms, end))
		farm->end_path = 1;
	if (error(farm, 1))
		return ;
	while (end->numants < farm->numants)
	{
		move_ants(start, &ants_moved);
		while (ants_moved)
			ft_list_pop(&ants_moved);
		ft_putchar('\n');
	}
}

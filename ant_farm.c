/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_farm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmthombe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 01:51:03 by mmthombe          #+#    #+#             */
/*   Updated: 2017/12/15 01:51:21 by mmthombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room	*ft_create_room(char *name)
{
	t_room *room;

	room = (t_room *)malloc(sizeof(t_room));
	if (room != NULL)
	{
		room->name = name;
		room->adj_rooms = NULL;
		room->ant = 0;
		room->numants = 0;
		room->type = ROOM;
	}
	return (room);
}

t_room	*getroom(t_farm *farm, char *name)
{
	t_list *start;
	t_room *room;

	start = farm->rooms;
	while (start)
	{
		room = (t_room *)start->data;
		if (ft_strcmp(room->name, name) == 0)
			return (room);
		start = start->next;
	}
	return (NULL);
}

void	add_room(t_list **rooms, char *name, t_type type, int n)
{
	char	**stats;
	char	*rname;
	t_room	*room;

	stats = ft_strsplit(name, ' ');
	rname = stats[0];
	room = ft_create_room(rname);
	room->type = type;
	room->numants = n;
	ft_list_push_back(rooms, room);
}

void	add_adjroom(t_list **list, t_room *room)
{
	if (contains(*list, room) == 0)
		ft_list_push_back(list, room);
}

int		add_link(t_farm *farm, char *link)
{
	char	**names;
	t_room	*room1;
	t_room	*room2;

	if (valid_link(farm, link))
	{
		names = ft_strsplit(link, '-');
		room1 = getroom(farm, names[0]);
		if (room1 == NULL)
		{
			room1 = ft_create_room(names[0]);
			ft_list_push_back(&farm->rooms, room1);
		}
		room2 = getroom(farm, names[1]);
		if (room2 == NULL)
		{
			room2 = ft_create_room(names[1]);
			ft_list_push_back(&farm->rooms, room2);
		}
		add_adjroom(&room2->adj_rooms, room1);
		add_adjroom(&room1->adj_rooms, room2);
		return (1);
	}
	return (0);
}

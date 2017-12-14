

#include "lemin.h"

int		isnumeric(char *str)
{
	while (*str)
	{
		if (ft_isdigit(*str) == 0)
			return (0);
		str++;
	}
	return (1);
}

int		roomvalid(char *line)
{
	char **stats;

	stats = ft_strsplit(line, ' ');
	if (stats[2])
	{
		if (stats[3] || isnumeric(stats[1]) == 0 || isnumeric(stats[2]) == 0)
		{
			ft_putendl("ERROR");
			return (0);
		}
	}
	else
	{
		ft_putendl("ERROR");
		return (0);
	}
	return (1);
}

void	verify_path(t_room *room, t_list **exp_rooms)
{
	t_list			*adj_rooms;
	static t_list	*v_rooms = NULL;
	t_room			*rm;

	if (contains(*exp_rooms, room) == 0)
		ft_list_push_back(exp_rooms, room);
	if (room->type == END)
		return ;
	adj_rooms = room->adj_rooms;
	ft_list_push_back(&v_rooms, room);
	while (adj_rooms)
	{
		rm = (t_room *)adj_rooms->data;
		if (contains(v_rooms, rm) == 0 && rm->type != START)
			verify_path(rm, exp_rooms);
		adj_rooms = adj_rooms->next;
	}
	ft_list_pop(&v_rooms);
}

int		valid_link(t_farm *farm, char *link)
{
	char **links;

	links = ft_strsplit(link, '-');
	if (links[1])
	{
		if (links[2])
		{
			ft_putendl("ERROR");
			return (0);
		}
	}
	else
	{
		ft_putendl("ERROR");
		return (0);
	}
	farm->room_added = 1;
	return (1);
}

int		error(t_farm *farm, int path_verif)
{
	if (farm->numants == 0 || farm->room_added == 0 ||
		(farm->end_path == 0 && path_verif))
	{
		ft_putendl("ERROR");
		return (1);
	}
	return (0);
}

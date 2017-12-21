/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmthombe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 13:19:12 by mmthombe          #+#    #+#             */
/*   Updated: 2017/12/20 13:38:50 by mmthombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		add_startroom(t_farm *farm, int *stage)
{
	char	*line;

	if (get_next_line(0, &line) == 1)
	{
		ft_putendl(line);
		if (roomvalid(line))
		{
			add_room(&farm->rooms, line, START, farm->numants);
			*stage = 2;
			return (1);
		}
	}
	return(0);
}

int		add_endroom(t_farm *farm, int *stage)
{
	char	*line;

	if (get_next_line(0, &line) == 1)
	{
		ft_putendl(line);
		if (roomvalid(line))
		{
			add_room(&farm->rooms, line, END, 0);
			*stage = 3;
			return(1);
		}
	}
	return(0);
}

int		room_added(t_farm *farm, char *line, int *stage)
{
	if (ft_strcmp(&line[1], "#start") == 0 && *stage == 1)
	{
		if (add_startroom(farm, stage) == 0)
			return(0);
	}
	else if (ft_strcmp(&line[1], "#end") == 0 && *stage == 2)
		if (add_endroom(farm, stage) == 0)
			return(0);
	return(1);
}

int		create_farm(t_farm *farm)
{
	int		stage;
	char	*line;

	stage = 0;
	while (get_next_line(0, &line) == 1)
	{
		ft_putendl(line);
		if (isnumeric(line) && stage == 0)
		{
			farm->numants = ft_atoi(line);
			stage = 1;
		}
		else if (line[0] == '#' && stage > 0)
		{
			if (room_added(farm, line, &stage) == 0)
				return(0);
		}
		else if (ft_strchr(line, '-') && stage == 3)
			if (add_link(farm, line) == 0)
				return (0);
	}
	return(1);
}

int		main(void)
{
	t_farm *farm;

	farm = (t_farm *)malloc(sizeof(t_farm));
	farm->rooms = NULL;
	farm->numants = 0;
	farm->room_added = 0;
	farm->end_path = 0;
	if (create_farm(farm))
	{
		ft_putchar('\n');
		ant_path(farm);
	}
	return(0);
}

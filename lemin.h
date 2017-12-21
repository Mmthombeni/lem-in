/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmthombe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 23:20:58 by mmthombe          #+#    #+#             */
/*   Updated: 2017/12/18 12:09:49 by mmthombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LEMIN_H
#define __LEMIN_H

#include "libft/libft.h"

# define MAX_INT 42000

typedef enum		e_type
{
	START,
	END,
	ROOM
}					t_type;

typedef struct		s_room
{
	unsigned int	ant;
	unsigned int	numants;
	char 			*name;
	t_type			type;
	t_list			*adj_rooms;
}					t_room;

typedef	struct		s_farm
{
	unsigned int	numants;
	t_list			*rooms;
	int				room_added;
	int				end_path;
}					t_farm;

int					add_link(t_farm *farm, char *link);
int					error(t_farm *farm, int path_verif);
int					isnumeric(char *str);
int					roomvalid(char *str);
int					valid_link(t_farm *farm, char *link);
int					contains(t_list *rooms, t_room *room);
int					short_dist(t_room *room, int dist);
void				add_room(t_list **rooms, char *name, t_type type, int n);
void				ant_path(t_farm *farm);
void				move_ant(t_room *from, t_room *to, t_list **ants);
void				move_ants(t_room *room, t_list **list);
void				ants_from_start(t_room *start, t_list **list);
void				verify_path(t_room *room, t_list **exp_rooms);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 12:33:02 by ikozlov           #+#    #+#             */
/*   Updated: 2018/04/03 23:18:02 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "list.h"
#include "memory.h"
#include "ft_printf.h"

int		can_move(t_graph g, t_ant ant)
{
	t_vertex	next;

	if (ant.path == NULL)
		return (0);
	next = g.nodes[ant.path[ant.progress + 1]];
	if (next.type == END || next.ants == 0)
		return (1);
	return (0);
}

int		turn(t_graph g, t_ant *ants, int *fants, int ant_count)
{
	int		i;
	int		moved;

	ft_printf("\n");
	i = -1;
	moved = 0;
	while (++i < ant_count)
	{
		if (fants[i] == 0 && can_move(g, ants[i]))
		{
			g.nodes[ants[i].path[ants[i].progress]].ants--;
			ants[i].progress++;
			g.nodes[ants[i].path[ants[i].progress]].ants++;
			ft_printf("%sL%d-%s", moved == 1 ? " " : "",
				i, g.nodes[ants[i].path[ants[i].progress]].name);
			moved = 1;
		}
		if (g.nodes[ants[i].path[ants[i].progress]].type == END)
			fants[i] = 1;
	}
	return (moved);
}

void	set_maps(t_list *paths, t_ant *ants, int ant_c)
{
	int		i;
	int		len;
	int		shortest;
	t_list	*head;

	i = 0;
	shortest = paths->content_size / sizeof(int);
	while (i != ant_c)
	{
		head = paths;
		while (paths && i != ant_c)
		{
			len = (int)paths->content_size / sizeof(int);
			if (len == shortest
				|| (shortest != 2 && ant_c - i >= len))
			{
				ants[i].path = paths->content;
				paths = paths->next;
				i++;
			}
			else
				break ;
		}
		paths = head;
	}
}

void	move_ants(t_graph g, t_list *paths, t_ant *ants, int ant_count)
{
	int		*fants;

	fants = ft_memalloc(sizeof(int) * ant_count);
	set_maps(paths, ants, ant_count);
	while (turn(g, ants, fants, ant_count))
		continue ;
	ft_memdel((void **)&fants);
}

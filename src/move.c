/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 12:33:02 by ikozlov           #+#    #+#             */
/*   Updated: 2018/03/31 14:15:32 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "list.h"

size_t	int_tab_ind(int *a, size_t size, int el)
{
	size_t	i;

	i = -1;
	while (++i < size)
		if (a[i] == el)
			return (i);
	return (-1);
}

int		can_move(t_graph g, t_ant ant)
{
	t_vertex	current;

	current = g.nodes[ant.path[ant.progress + 1]];
	if (current.type == END || current.ants == 0)
		return (1);
	return (0);
}

int		turn(t_graph g, t_ant *ants, int ant_count)
{
	int		i;
	int		ant_at_end;

	ant_at_end = 0;
	while (ant_at_end != ant_count)
	{
		i = ant_at_end - 1;
		while (++i < ant_count)
		{
			if (ants[i].path != NULL && can_move(g, ants[i]))
				ants[i].progress++;
			if (g.nodes[ants[i].path[ants[i].progress]].type == END)
				ant_at_end++;
		}
	}
	return (1);
}

void	set_maps(t_list *paths, t_ant *ants, int ant_c)
{
	int		i;
	t_list	*head;

	i = 0;
	while (i != ant_c)
	{
		head = paths;
		while (paths && i != ant_c)
		{
			ants[i].path = (int *)paths->content;
			if (ant_c - i < (int)(paths->content_size / sizeof(int)))
				paths = paths->next;
			i++;
		}
		paths = head;
	}
}

void	move_ants(t_graph g, t_list *paths, t_ant *ants, int ant_count)
{
	set_maps(paths, ants, ant_count);
	turn(g, ants, ant_count);
	return ;
}

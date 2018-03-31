/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 12:33:02 by ikozlov           #+#    #+#             */
/*   Updated: 2018/03/31 16:49:23 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "list.h"
#include "ft_printf.h"

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
	t_vertex	next;

	next = g.nodes[ant.path[ant.progress + 1]];
	if (next.type == END || next.ants == 0)
		return (1);
	return (0);
}

int		turn(t_graph g, t_ant *ants, int ant_count)
{
	int		i;
	int		ant_at_end;
	int		need_space;

	ant_at_end = 0;
	while (ant_at_end != ant_count)
	{
		need_space = 0;
		i = ant_at_end - 1;
		while (++i < ant_count)
		{
			if (ants[i].path != NULL && can_move(g, ants[i]))
			{
				ants[i].progress++;
				ft_printf("%sL%d-%d", need_space == 1 ? " " : "",
					i, g.nodes[ants[i].path[ants[i].progress]].number);
				need_space = 1;
			}
			if (g.nodes[ants[i].path[ants[i].progress]].type == END)
				ant_at_end++;
		}
		ft_printf("\n");
	}
	return (1);
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
			if (len == shortest || ant_c - i >= len)
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
	set_maps(paths, ants, ant_count);
	turn(g, ants, ant_count);
	return ;
}

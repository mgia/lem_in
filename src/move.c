/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 12:33:02 by ikozlov           #+#    #+#             */
/*   Updated: 2018/04/02 14:05:49 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "list.h"
#include "memory.h"
#include "ft_printf.h"

void	set_short_paths_rooms(t_graph g, t_list *paths)
{
	int			i;
	int			len;
	int			shortest;
	t_vertex	*current;

	shortest = (int)paths->content_size / sizeof(int);
	while (paths)
	{
	i = -1;
		len = (int)paths->content_size / sizeof(int);
		while (len == shortest && ++i < len)
		{
			current = &g.nodes[((int *)paths->content)[i]];
			if (current->type != START && current->type != END)
				current->type = POSP;
		}
		paths = paths->next;
	}
}

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

int		turn(t_graph g, t_ant *ants, int ant_count)
{
	int		i;
	int		*fants;
	int		need_space;

	need_space = 1;
	fants = ft_memalloc(sizeof(int) * ant_count);
	while (need_space)
	{
		ft_printf("\n");
		need_space = 0;
		i = -1;
		while (++i < ant_count)
		{
			if (fants[i] == 0 && can_move(g, ants[i]))
			{
				g.nodes[ants[i].path[ants[i].progress]].ants--;
				ants[i].progress++;
				g.nodes[ants[i].path[ants[i].progress]].ants++;
				ft_printf("%sL%d-%d", need_space == 1 ? " " : "",
					i, g.nodes[ants[i].path[ants[i].progress]].number);
				need_space = 1;
			}
			if (g.nodes[ants[i].path[ants[i].progress]].type == END)
				fants[i] = 1;
		}
	}
	ft_memdel((void **)&fants);
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

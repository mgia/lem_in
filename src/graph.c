/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:35:44 by ikozlov           #+#    #+#             */
/*   Updated: 2018/03/29 22:52:39 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "list.h"
#include "memory.h"
#include <stdlib.h>

void	add_edge(t_graph g, int p, int c)
{
	t_vertex	*l;
	t_list		*child;

	l = g.nodes;
	child = NULL;
	child = ft_lstnew(NULL, 0);
	child->content = &l[c];
	child->content_size = sizeof(l[c]);
	if (l[p].children == NULL)
		l[p].children = child;
	else
		ft_lstadd(&l[p].children, child);
	c++;
}

void	free_vertex(t_vertex v)
{
	free(v.children);
}

void	free_graph(t_graph g)
{
	int		i;

	i = -1;
	while (++i < g.V)
		if (g.nodes[i].children)
			ft_lstdel(&g.nodes[i].children, ft_save_content);
	ft_memdel((void **)&g.nodes);
}

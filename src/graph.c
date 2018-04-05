/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:35:44 by ikozlov           #+#    #+#             */
/*   Updated: 2018/04/04 20:02:13 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "list.h"
#include "memory.h"
#include <stdio.h>
#include <stdlib.h>

int		pathcmp(t_list *a, t_list *b)
{
	return ((int)(a->content_size - b->content_size));
}

void	add_edge(t_graph *g, int p, int c)
{
	t_vertex	*l;
	t_list		*child;

	l = g->nodes;
	child = NULL;
	child = ft_lstnew(NULL, 0);
	child->content = &l[c];
	child->content_size = sizeof(l[c]);
	if (l[p].children == NULL)
		l[p].children = child;
	else
	{
		if (!ft_lsthas(l[p].children, child, pathcmp))
			ft_lstadd(&l[p].children, child);
		else
			ft_lstdelone(&child, ft_save_content);
	}
	c++;
}

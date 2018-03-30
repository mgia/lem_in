/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:35:44 by ikozlov           #+#    #+#             */
/*   Updated: 2018/03/29 21:37:51 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "list.h"

void	add_edge(t_graph g, int p, int c)
{
	t_vertex	*l;
	t_list		*child;

	l = g.nodes;
	child = ft_lstnew(&l[c], sizeof(l[c]));
	child->content = &l[c];
	if (l[p].children == NULL)
		l[p].children = child;
	else
		ft_lstadd(&l[p].children, child);
}

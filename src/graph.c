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

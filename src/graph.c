/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:35:44 by ikozlov           #+#    #+#             */
/*   Updated: 2018/03/29 20:45:53 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "list.h"

void	add_edge(t_vertex *l, int p, int c)
{
	t_list	*child;

	child = ft_lstnew(&l[c], sizeof(l[c]));
	child->content = &l[c];
	if (l[p].children == NULL)
		l[p].children = child;
	else
		ft_lstadd(&l[p].children, child);
}

size_t	ft_graphlen(t_vertex *g)
{
	int		len;

	len = 0;
	while (g[len].number != -1)
		len++;
	return (len);
}

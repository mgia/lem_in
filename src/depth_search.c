/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   depth_search.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 19:44:40 by ikozlov           #+#    #+#             */
/*   Updated: 2018/03/31 18:36:14 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "memory.h"
#include "numbers.h"
#include "lem_in.h"
#include <stdio.h>
#include <stdlib.h>

void	print_int_arr(int *a, int size)
{
	int		i;

	i = -1;
	while (++i < size)
		printf("%d%s", a[i], i == size ? " " : "");
	printf("\n");
}

t_list	*find_paths_rec(t_vertex c, t_vertex e, int *p, int p_ind)
{
	t_list		*kids;
	t_list		*buf;
	t_list		*res;
	t_vertex	kid;

	p[p_ind] = c.number;
	kids = c.children;
	res = NULL;
	if (c.number == e.number)
		res = ft_lstnew(p, (p_ind + 1) * sizeof(int));
	else
		while (kids)
		{
			kid = *(t_vertex *)kids->content;
			if (is_in_arr(p, p_ind, kid.number) < 0)
			{
				buf = find_paths_rec(kid, e, p, p_ind + 1);
				if (buf && !res)
					res = buf;
				else if (buf && res)
					ft_lstaddback(&res, buf);
			}
			kids = kids->next;
		}
	return (res);
}

t_list	*find_paths(t_graph g, int s, int e)
{
	int		*path;
	t_list	*paths;

	path = ft_memalloc(g.V * sizeof(int));
	paths = find_paths_rec(g.nodes[s], g.nodes[e], path, 0);
	free(path);
	if (!paths)
		error("Error: No Path");
	return (paths);
}

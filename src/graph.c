/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:35:44 by ikozlov           #+#    #+#             */
/*   Updated: 2018/03/29 19:37:48 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "list.h"
#include <stdlib.h>
#include <stdio.h>

void	add_edge(t_vertex *l, int p, int c)
{
	t_list	*child;

	child = ft_lstnew(&l[c], sizeof(l[c]));
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

void	print_int_arr(int *a, int size)
{
	int		i;

	i = -1;
	while (++i < size)
		printf("%d%s", a[i], i == size ? " " : "");
	printf("\n");
}

void	print_paths_rec(t_vertex *g, int c, int e, int *v, int *p, int p_ind)
{
	int			i;
	t_list		*tmp;
	t_vertex	*kid;

	v[c] = 1;
	p[p_ind] = c;
	p_ind++;
	if (c == e)
		print_int_arr(p, p_ind);
	else
	{
		i = -1;
		tmp = g[c].children;
		while (tmp)
		{
			kid = (t_vertex *)tmp->content;
			tmp = tmp->next;
			if (!v[kid->number])
				print_paths_rec(g, kid->number, e, v, p, p_ind);
		}
	}
	p_ind--;
	v[c] = 0;
}

void	print_paths(t_vertex *g, int s, int e)
{
	int		*visited;
	int		*path;
	int		graphlen;
	int		i;

	graphlen = ft_graphlen(g);
	visited = malloc(sizeof(int) * graphlen);
	path = malloc(sizeof(int) * graphlen);
	i = -1;
	while (++i < graphlen)
	{
		path[i] = 0;
		visited[i] = 0;
	}
	print_paths_rec(g, s, e, visited, path, 0);
	free(visited);
	free(path);
}

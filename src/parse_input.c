/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 22:08:08 by mtan              #+#    #+#             */
/*   Updated: 2018/04/03 22:08:13 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

void	create_graph(t_graph *g, t_vertex tmp[10000], int *start, int *end)
{
	int i;

	g->nodes = malloc(sizeof(t_vertex) * g->V);
	i = -1;
	while (++i < g->V)
	{
		g->nodes[i].number = i;
		g->nodes[i].name = ft_strdup(tmp[i].name);
		g->nodes[i].type = tmp[i].type ? tmp[i].type : 0;
		(*start) = tmp[i].type == START ? i : (*start);
		(*end) = tmp[i].type == END ? i : (*end);
		g->nodes[i].children = NULL;
		g->nodes[i].ants = 0;
	}
}

void	parse_input(t_ant **ants, int *ant_count, t_list **p, t_graph *g)
{
	t_vertex	tmp[10000];
	char		*line;
	int			i;
	int			start;
	int			end;

	parse_ants(ants, ant_count);
	line = parse_vertex(tmp, &i);
	g->V = i;
	create_graph(g, tmp, &start, &end);
	parse_links(g, tmp, line);
	i = -1;
	while (++i < g->V)
		free(tmp[i].name);
	i = MIN(ft_lstcount(g->nodes[start].children),
		ft_lstcount(g->nodes[end].children));
	*p = breadth_search(*g, g->nodes[start], g->nodes[end], i);
}

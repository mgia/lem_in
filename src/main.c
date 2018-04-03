/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 10:56:53 by mtan              #+#    #+#             */
/*   Updated: 2018/04/03 13:09:09 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

void	ivan_test(void)
{
	t_graph		g;
	t_list		*p;
	t_ant		*ants;
	int			i;

	g.V = 4;
	g.nodes = malloc(sizeof(t_vertex) * g.V);
	i = -1;
	while (++i < g.V)
	{
		g.nodes[i].type = REGULAR;
		g.nodes[i].number = i;
		g.nodes[i].children = NULL;
		g.nodes[i].ants = 0;
	}
	add_edge(&g, 0, 1);
	add_edge(&g, 0, 2);
	add_edge(&g, 0, 3);
	add_edge(&g, 2, 0);
	add_edge(&g, 2, 1);
	add_edge(&g, 1, 3);
	g.nodes[2].type = START;
	g.nodes[3].type = END;
	int a = 42;
	// p = find_paths(g, 2, 3);
	p = breadth_search(g, g.nodes[2], g.nodes[3]);
	ants = malloc(sizeof(t_ant) * a);
	i = -1;
	while (++i < a)
	{
		ants[i].progress = 0;
		ants[i].path = NULL;
		ants[i].number = a;
	}
	// move_ants(g, p, ants, a);
	ft_lstdel(&p, ft_free_content);
	free_graph(&g);
}

int		main(void)
{
	// t_graph		g;
	// t_ant		*ants;
	// int			ant_count;
	// t_list		*p;

	// parse_input(&ants, &ant_count, &p, &g);
	// print_paths(p);
	// move_ants(g, p, ants, ant_count);
	// free_all(p, &g, ants);
	ivan_test();
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 10:56:53 by mtan              #+#    #+#             */
/*   Updated: 2018/03/30 10:56:54 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

// void	ivan_test(void)
// {
// 	t_graph		g;
// 	t_list		*p;
// 	int			i;
//
// 	g.V = 4;
// 	g.nodes = malloc(sizeof(t_vertex) * g.V);
// 	i = -1;
// 	while (++i < g.V)
// 	{
// 		g.nodes[i].number = i;
// 		g.nodes[i].children = NULL;
// 	}
// 	add_edge(g, 0, 1);
// 	add_edge(g, 0, 2);
// 	add_edge(g, 0, 3);
// 	add_edge(g, 2, 0);
// 	add_edge(g, 2, 1);
// 	add_edge(g, 1, 3);
// 	p = find_paths(g, 2, 3);
// 	ft_lstdel(&p, ft_free_content);
// 	free_graph(&g);
// }

int		main(void)
{
	t_ant		ants;
	t_vertex	v[42];
	t_graph		g;
	t_list		*p;

	p = parse_input(&ants, v, &g);
	printf("what %p\n", &g);
	print_paths(p);
	print_names(v, g);
	free_all(p, &g);
	return (0);
}

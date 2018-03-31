/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 10:56:53 by mtan              #+#    #+#             */
/*   Updated: 2018/03/31 14:31:56 by ikozlov          ###   ########.fr       */
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
		g.nodes[i].number = i;
		g.nodes[i].children = NULL;
		g.nodes[i].ants = 0;
	}
	add_edge(g, 0, 1);
	add_edge(g, 0, 2);
	add_edge(g, 0, 3);
	add_edge(g, 2, 0);
	add_edge(g, 2, 1);
	add_edge(g, 1, 3);
	g.nodes[2].type = START;
	g.nodes[3].type = END;
	p = find_paths(g, 2, 3);
	ants = malloc(sizeof(t_ant));
	ants->progress = -1;
	ants->path = NULL;
	ants->number = 1;
	move_ants(g, p, ants, 1);
	ft_lstdel(&p, ft_free_content);
	free_graph(g);
}

int		main(void)
{
	// t_ant		ants;
	// t_vertex	v[42];
	// t_list		*p;
	// t_list		*head;

	// // g = NULL;
	// p = parse_input(&ants, v);
	// head = p;
	// while (p)
	// {
	// 	print_int_arr(p->content, p->content_size / 4);
	// 	p = p->next;
	// }
	// ft_lstdel(&head, ft_free_content);
	// // can still access names via v t_vertex after freeing graph
	// ft_printf("%s\n", v[0].name);
	// ft_printf("%s\n", v[1].name);
	// ft_printf("%s\n", v[2].name);
	// ft_printf("%s\n", v[3].name);
	ivan_test();
	return (0);
}

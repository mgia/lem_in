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

void	ivan_test(void)
{
	t_graph		g;
	t_list		*p;
	int			i;

	g.V = 4;
	g.nodes = malloc(sizeof(t_vertex) * g.V);
	i = -1;
	while (++i < g.V)
	{
		g.nodes[i].number = i;
		g.nodes[i].children = NULL;
	}
	add_edge(g, 0, 1);
	add_edge(g, 0, 2);
	add_edge(g, 0, 3);
	add_edge(g, 2, 0);
	add_edge(g, 2, 1);
	add_edge(g, 1, 3);
	p = find_paths(g, 2, 3);
	ft_lstdel(&p, ft_free_content);
	free_graph(g);
}

int		main(void)
{
	t_ant		ants;
	t_vertex	v[42];
	t_list		*p;
	t_list		*head;

	// g = NULL;
	p = parse_input(&ants, v);
	head = p;
	while (p)
	{
		print_int_arr(p->content, p->content_size / 4);
		p = p->next;
	}
	ft_lstdel(&head, ft_free_content);
	// can still access names via v t_vertex after freeing graph
	ft_printf("%s\n", v[0].name);
	ft_printf("%s\n", v[1].name);
	ft_printf("%s\n", v[2].name);
	ft_printf("%s\n", v[3].name);
	return (0);
}

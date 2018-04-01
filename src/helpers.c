/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 14:12:51 by mtan              #+#    #+#             */
/*   Updated: 2018/03/31 14:12:52 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

void	error(const char *str)
{
	ft_putendl(str);
	exit(1);
}

void	free_graph(t_graph *g)
{
	int		i;

	i = -1;
	while (++i < g->V)
	{
		free(g->nodes[i].name);
		if (g->nodes[i].children)
			ft_lstdel(&g->nodes[i].children, ft_save_content);
	}
	ft_memdel((void **)&g->nodes);
}

void	free_all(t_list *p, t_graph *g, t_ant *ants)
{
	free_graph(g);
	ft_lstdel(&p, ft_free_content);
	free(ants);
}

void	print_paths(t_list *p)
{
	while (p)
	{
		print_int_arr(p->content, p->content_size / 4);
		p = p->next;
	}
}

void	print_names(t_vertex *v, t_graph g)
{
	int i;

	i = -1;
	while (++i < g.V)
		ft_printf("Vertex [%d]: %s\n", i, v[i].name);
}

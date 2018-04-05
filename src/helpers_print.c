/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 20:21:25 by mtan              #+#    #+#             */
/*   Updated: 2018/04/04 20:21:26 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

void	print_rooms_info(t_graph g)
{
	int		i;

	i = -1;
	while (++i < g.V)
	{
		ft_printf("#%d:\n", i);
		ft_printf("Type: %d\n", g.nodes[i].type);
	}
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

void	print_int_arr(int *a, int size)
{
	int		i;

	i = -1;
	while (++i < size)
		ft_printf("%s%d", i == 0 ? "" : " ", a[i]);
	ft_printf("\n");
}

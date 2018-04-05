/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 14:12:51 by mtan              #+#    #+#             */
/*   Updated: 2018/04/02 15:20:56 by ikozlov          ###   ########.fr       */
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 22:08:08 by mtan              #+#    #+#             */
/*   Updated: 2018/04/04 20:27:29 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

static void	free_reference(char **tmp)
{
	free(tmp[0]);
	free(tmp[1]);
	free(tmp);
}

void		store_link(t_graph *g, t_vertex *v, char *line)
{
	char	**tmp;
	int		x;
	int		y;
	int		j;

	tmp = ft_strsplit(line, '-');
	j = 0;
	while (j < g->v && !ft_strequ(tmp[0], v[j].name))
		j++;
	if (j >= g->v)
		error("Error: No matching room for link");
	x = j;
	j = 0;
	while (j < g->v && !ft_strequ(tmp[1], v[j].name))
		j++;
	if (j >= g->v)
		error("Error: No matching room for link");
	y = j;
	ft_putendl(line);
	add_edge(g, x, y);
	add_edge(g, y, x);
	free_reference(tmp);
	free(line);
}

void		parse_links(t_graph *g, t_vertex *v, char *line)
{
	if (line == NULL)
		error("Error: No Links");
	store_link(g, v, line);
	while (get_next_line(0, &line))
	{
		if (line[0] == '#')
			put_line(line);
		else if (!ft_strstr(line, "-"))
			error("Error: Bad Links");
		else
			store_link(g, v, line);
	}
}

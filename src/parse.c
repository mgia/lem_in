/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 14:11:16 by mtan              #+#    #+#             */
/*   Updated: 2018/03/31 14:11:25 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

void	parse_ants(t_ant *ants)
{
	char	*line;
	int		i;

	i = 0;
	if (!get_next_line(0, &line))
		error("Error: No File");
	ants->number = ft_atoi(line);
	if (!ft_isdigit_str(line) || ants->number <= 0)
		error("Error: No Ants");
	ft_putendl(line);
	free(line);
}

char	*parse_vertex(t_vertex *v, int *i)
{
	char		*line;
	int			ends;

	*i = 0;
	ends = 0;
	while (get_next_line(0, &line))
	{
		if (ft_strchr(line, '-'))
			break ;
		else if (line[0] == '#')
			parse_comment(line, &ends, i);
		else
			store_vertex(v, line, *i);
		(*i)++;
		ft_putendl(line);
		free(line);
	}
	if (!*i)
		error("Error: No rooms");
	if (ends < 2)
		error("Error: No Start or End");
	v[*i].number = -1;
	return (line);
}

void	parse_links(t_graph *g, t_vertex *v, char *line)
{
	if (line == NULL)
		error("Error: No Links");
	store_link(g, v, line);
	while (get_next_line(0, &line))
		store_link(g, v, line);
}

void	store_link(t_graph *g, t_vertex *v, char *line)
{
	char	**tmp;
	int		x;
	int		y;
	int		j;

	tmp = ft_strsplit(line, '-');
	j = 0;
	while (!ft_strequ(tmp[0], v[j].name))
		j++;
	x = j;
	j = 0;
	while (!ft_strequ(tmp[1], v[j].name))
		j++;
	y = j;
	ft_putendl(line);
	add_edge(g, x, y);
	free(tmp[0]);
	free(tmp[1]);
	free(tmp);
	free(line);
}

t_list	*parse_input(t_ant *ants, t_vertex *v, t_graph *g)
{
	char		*line;
	t_list		*p;
	int			i;

	parse_ants(ants);
	line = parse_vertex(v, &i);
	g->V = i;
	g->nodes = malloc(sizeof(t_vertex) * g->V);
	i = -1;
	while (++i < g->V)
	{
		g->nodes[i].number = i;
		g->nodes[i].children = NULL;
	}
	parse_links(g, v, line);
	p = find_paths(*g, 2, 3);
	return (p);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 11:35:17 by mtan              #+#    #+#             */
/*   Updated: 2018/03/30 11:35:17 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

void	parse_coordinates(t_vertex *v, char *line, int i, int j)
{
	int x;
	int y;

	while (line[j] == ' ')
		j++;
	if (!ft_isdigit(line[j]))
		error("Error: forbidden co-ordinates");
	x = ft_atoi(&line[j]);
	while (ft_isdigit(line[j]))
		j++;
	while (line[j] == ' ')
		j++;
	if (!ft_isdigit(line[j]))
		error("Error: forbidden co-ordinates");
	y = ft_atoi(&line[j]);
	v[i].pos.x = x;
	v[i].pos.y = y;
}

void	parse_comment(char *line, int *ends, int *i)
{
	if (line[0] == '#' && line[1] == '#')
	{
		if (ft_strstr(line, "start") || ft_strstr(line, "end"))
		{
			(*ends)++;
			(*i)--;
		}
	}
}

void	store_vertex(t_vertex *v, char *line, int i)
{
	int j;

	j = 0;
	if (line[0] == 'L')
		error("Error: Illegal name");
	while (line[j] != ' ')
		j++;
	v[i].name = ft_strndup(line, j);
	v[i].number = i;
	v[i].children = NULL;
	parse_coordinates(v, line, i, j);
}

void	store_link(t_graph g, t_vertex *v, char *line)
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

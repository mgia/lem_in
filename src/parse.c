/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 11:35:12 by mtan              #+#    #+#             */
/*   Updated: 2018/03/30 11:35:13 by mtan             ###   ########.fr       */
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

char	*parse_vertex(t_vertex *v)
{
	char		*line;
	int			ends;
	int			i;

	i = 0;
	ends = 0;
	while (get_next_line(0, &line))
	{
		if (ft_strchr(line, '-'))
			break ;
		else if (line[0] == '#')
			parse_comment(line, &ends, &i);
		else
			store_vertex(v, line, i);
		i++;
		ft_putendl(line);
		free(line);
	}
	if (!i)
		error("Error: No rooms");
	if (ends < 2)
		error("Error: No Start or End");
	v[i].number = -1;
	return (line);
}

void	parse_links(t_vertex *v, char *line)
{
	if (line == NULL)
		error("Error: No Links");
	store_link(v, line);
	while (get_next_line(0, &line))
		store_link(v, line);
}

void	parse_input(t_ant *ants, t_vertex *v)
{
	char *line;

	parse_ants(ants);
	line = parse_vertex(v);
	parse_links(v, line);
}

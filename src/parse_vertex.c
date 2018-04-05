/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vertex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 22:08:08 by mtan              #+#    #+#             */
/*   Updated: 2018/04/03 22:08:13 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

static void	check_coordinates(char *line)
{
	while (*line == ' ')
		line++;
	while (*line != ' ')
	{
		if (!ft_isdigit(*line))
			error("Error: Bad coordinates");
		line++;
	}
	while (*line == ' ')
		line++;
	while (*line != ' ' && *line)
	{
		if (!ft_isdigit(*line))
			error("Error: Bad coordinates");
		line++;
	}
}

static void	check_ends(int *prev, int *ends)
{
	if (*prev == 1)
	{
		(*ends)++;
		(*prev) = 0;
	}
}

static void	check_errors(char *line, int i, int ends, int prev)
{
	if (!line)
		error("Error: No Links");
	if (!i)
		error("Error: No rooms or illegal name");
	if (ends < 2 || prev)
		error("Error: No start/end or illegal name or underflow");
}

void		store_vertex(t_vertex *v, char *line, int i)
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
	check_coordinates(&line[j]);
}

char		*parse_vertex(t_vertex *v, int *i)
{
	char		*line;
	int			ends;
	int			prev;

	*i = 0;
	ends = 0;
	prev = 0;
	while (get_next_line(0, &line))
	{
		if (ft_strchr(line, '-'))
			break ;
		else if (line[0] == '#')
			parse_comment(line, i, v, &prev);
		else
		{
			check_ends(&prev, &ends);
			store_vertex(v, line, *i);
		}
		(*i)++;
		put_line(line);
		line = NULL;
	}
	check_errors(line, *i, ends, prev);
	return (line);
}

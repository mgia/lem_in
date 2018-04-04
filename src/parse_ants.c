/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 22:08:08 by mtan              #+#    #+#             */
/*   Updated: 2018/04/03 22:08:13 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

void	store_ants(t_ant **ants, int *ant_count)
{
	int		i;

	*ants = malloc(sizeof(t_ant) * (*ant_count));
	i = -1;
	while (++i < *ant_count)
	{
		(*ants)[i].progress = 0;
		(*ants)[i].path = NULL;
		(*ants)[i].number = *ant_count;
	}
}

void	parse_ants(t_ant **ants, int *ant_count)
{
	char	*line;

	if (!get_next_line(0, &line))
		error("Error: No File");
	if (!line)
		error("Error: Empty File");
	while (line[0] == '#')
	{
		put_line(line);
		get_next_line(0, &line);
	}
	*ant_count = ft_atoi(line);
	if (!ft_isdigit_str(line) || *ant_count <= 0)
		error("Error: No Ants or bad Ants");
	store_ants(ants, ant_count);
	put_line(line);
}

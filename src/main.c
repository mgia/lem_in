/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 10:56:53 by mtan              #+#    #+#             */
/*   Updated: 2018/04/03 23:16:27 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

int		main(void)
{
	t_graph		g;
	t_ant		*ants;
	int			ant_count;
	t_list		*p;

	parse_input(&ants, &ant_count, &p, &g);
	move_ants(g, p, ants, ant_count);
	free_all(p, &g, ants);
	return (0);
}

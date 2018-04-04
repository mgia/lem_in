/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 21:14:23 by ikozlov           #+#    #+#             */
/*   Updated: 2018/04/03 21:16:04 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "memory.h"

void	init_path(t_path *p, size_t size)
{
	p->size = 0;
	p->array = ft_memalloc(sizeof(int) * size);
}

void	path_push_back(t_path *p, int el)
{
	p->array[p->size] = el;
	p->size++;
}

t_path	*path_create_copy(t_path p, size_t size)
{
	int		i;
	t_path	*res;

	res = ft_memalloc(sizeof(t_path));
	init_path(res, size);
	i = -1;
	while (++i < (int)p.size)
		res->array[i] = p.array[i];
	res->size = p.size;
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breadth_search.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 19:39:46 by ivankozlov        #+#    #+#             */
/*   Updated: 2018/04/04 20:26:58 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "memory.h"
#include "queue.h"
#include "numbers.h"
#include "ft_printf.h"
#include "list.h"

void	del_queue_item(void *item, size_t size)
{
	t_path	tmp;

	tmp = *(t_path *)item;
	ft_memdel((void **)&tmp.array);
	ft_free_content(item, size);
}

void	iterate_children(t_vertex node, t_path path, size_t path_max_size)
{
	int		kid;
	t_path	*tmp;

	while (node.children)
	{
		kid = (*(t_vertex *)node.children->content).number;
		if (is_in_arr(path.array, path.size, kid) < 0)
		{
			tmp = path_create_copy(path, path_max_size);
			path_push_back(tmp, kid);
			q_push(tmp, sizeof(t_path));
			ft_memdel((void **)&tmp);
		}
		node.children = node.children->next;
	}
}

t_list	*breadth_search(t_graph g, t_vertex c, t_vertex e, size_t max)
{
	t_path		*p;
	t_list		*paths;

	paths = NULL;
	q_init();
	p = ft_memalloc(sizeof(t_path));
	init_path(p, g.v);
	path_push_back(p, c.number);
	q_push(p, sizeof(t_path));
	ft_memdel((void **)&p);
	while (q_peek() && ft_lstcount(paths) < max)
	{
		p = (t_path *)q_pop();
		c = g.nodes[p->array[p->size - 1]];
		if (c.number == e.number && paths == NULL)
			paths = ft_lstnew(p->array, p->size * sizeof(int));
		else if (c.number == e.number && paths != NULL)
			ft_lstaddback(&paths,
				ft_lstnew(p->array, p->size * sizeof(int)));
		iterate_children(c, *p, g.v);
		ft_memdel((void **)&p->array);
		ft_memdel((void **)&p);
	}
	q_destroy(del_queue_item);
	return (paths);
}

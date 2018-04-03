/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breadth_search.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 19:39:46 by ivankozlov        #+#    #+#             */
/*   Updated: 2018/04/02 20:51:32 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "memory.h"
#include "queue.h"
#include "list.h"

// // utility function for finding paths in graph
// // from source to destination
// void findpaths(vector<vector<int> >&g, int src, 
//                                  int dst, int v)
// {
//     // create a queue which stores
//     // the paths
//     queue<vector<int> > q;
 
//     // path vector to store the current path
//     vector<int> path;
//     path.push_back(src);
//     q.push(path);
//     while (!q.empty()) {
//         path = q.front();
//         q.pop();
//         int last = path[path.size() - 1];
 
//         // if last vertex is the desired destination
//         // then print the path
//         if (last == dst) 
//             printpath(path);        
 
//         // traverse to all the nodes connected to 
//         // current vertex and push new path to queue
//         for (int i = 0; i < g[last].size(); i++) {
//             if (isNotVisited(g[last][i], path)) {
//                 vector<int> newpath(path);
//                 newpath.push_back(g[last][i]);
//                 q.push(newpath);
//             }
//         }
//     }
// }

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

t_list	*breadth_search(t_graph g, t_vertex c, t_vertex e)
{
	t_path		path;
	t_list		*tmp;
	t_vertex	last;
	t_list		*paths;

	paths = NULL;
	q_init();
	init_path(&path, g.V);
	path_push_back(&path, c.number);
	q_push(&path, sizeof(t_path));
	while (q_peek())
	{
		path = *(t_path *)q_pop();
		last = g.nodes[path.array[path.size - 1]];
		if (last.number == e.number)
		{
			tmp = ft_lstnew(path.array, path.size * sizeof(int));
			paths == NULL ? paths = tmp : ft_lstaddback(&paths, tmp);
			while (last.children)
			{
				path_push_back(&path, (*(t_vertex *)last.children->content).number);
				q_push(&path, path.size * sizeof(int));
				last.children = last.children->next;
			}
		}
	}
	q_destroy();
	ft_memdel((void **)&path.array);
	return (paths);
}

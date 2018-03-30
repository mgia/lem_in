// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   depth_search.c                                     :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2018/03/29 19:44:40 by ikozlov           #+#    #+#             */
// /*   Updated: 2018/03/29 21:30:33 by ikozlov          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */
//
// #include "list.h"
// #include "lem_in.h"
// #include <stdio.h>
// #include <stdlib.h>
//
// void	print_int_arr(int *a, int size)
// {
// 	int		i;
//
// 	i = -1;
// 	while (++i < size)
// 		printf("%d%s", a[i], i == size ? " " : "");
// 	printf("\n");
// }
//
// int		is_in_arr(int *a, int size, int el)
// {
// 	int		i;
//
// 	i = -1;
// 	while (++i < size)
// 		if (a[i] == el)
// 			return (1);
// 	return (0);
// }
//
// t_list	*find_paths_rec(t_vertex c, t_vertex e, int *p, int p_ind)
// {
// 	t_list		*kids;
// 	t_list		*buf;
// 	t_list		*res;
// 	t_vertex	kid;
//
// 	p[p_ind] = c.number;
// 	kids = c.children;
// 	res = NULL;
// 	if (c.number == e.number)
// 		res = ft_lstnew(p, (p_ind + 1) * sizeof(int));
// 	else
// 		while (kids)
// 		{
// 			kid = *(t_vertex *)kids->content;
// 			kids = kids->next;
// 			if (!is_in_arr(p, p_ind, kid.number))
// 			{
// 				buf = find_paths_rec(kid, e, p, p_ind + 1);
// 				if (buf && !res)
// 					res = buf;
// 				else if (buf && res)
// 					ft_lstaddlst(&res, buf);
// 			}
// 		}
// 	return (res);
// }
//
// t_list	*find_paths(t_vertex *g, int s, int e)
// {
// 	int		i;
// 	int		*path;
// 	int		graphlen;
// 	t_list	*paths;
//
// 	graphlen = ft_graphlen(g);
// 	path = malloc(sizeof(int) * graphlen);
// 	i = -1;
// 	while (++i < graphlen)
// 		path[i] = 0;
// 	paths = find_paths_rec(g[s], g[e], path, 0);
// 	free(path);
// 	return (paths);
// }

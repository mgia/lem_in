/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 14:00:21 by ikozlov           #+#    #+#             */
/*   Updated: 2018/03/29 22:24:45 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "math.h"
# include "list.h"
# include "matrix.h"

/*
** Structures
*/

struct					s_vertex
{
	char				*name;
	int					number;
	t_list				*children;
	t_point				pos;
};
typedef struct s_vertex	t_vertex;

struct					s_graph
{
	int					V;
	t_vertex			*nodes;
};
typedef struct s_graph	t_graph;

struct					s_ant
{
	int					number;
	char				*location;
};
typedef struct s_ant	t_ant;

/*
** Functions
*/

int		ft_isdigit_str(char *str);
char	*ft_strndup(const char *s, int n);
// void	print_matrix(t_matrix *m, const char *type);

void	print_int_arr(int *a, int size);
int		is_in_arr(int *a, int size, int el);
void	add_edge(t_graph g, int p, int c);
void	free_graph(t_graph g);
t_list	*find_paths(t_graph g, int s, int e);

#endif

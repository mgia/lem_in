/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 14:00:21 by ikozlov           #+#    #+#             */
/*   Updated: 2018/03/31 18:44:09 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "math.h"
# include "list.h"
# include "matrix.h"
# include <stdio.h>

# define REGULAR 0
# define START 1
# define END 2

/*
** Structures
*/

struct					s_vertex
{
	char				*name;
	int					number;
	int					ants;
	int					type;
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
	int					progress;
	int					*path;
};
typedef struct s_ant	t_ant;

/*
** Parsers
*/

void	parse_ants(t_ant **ants, int *ant_count);
char	*parse_vertex(t_vertex *v, int *i);
void	parse_links(t_graph *g, t_vertex *v, char *line);
void	store_link(t_graph *g, t_vertex *v, char *line);
void	parse_input(t_ant **ants, int *ant_count, t_list **p, t_graph *g);
void	parse_comment(char *line, int *ends, int *i, t_vertex *v);
void	store_vertex(t_vertex *v, char *line, int i);

/*
** Algorithm
*/

void	add_edge(t_graph *g, int p, int c);
t_list	*find_paths(t_graph g, int s, int e);
void	move_ants(t_graph g, t_list *paths, t_ant *ants, int ant_count);

/*
** Helpers
*/

void	error(const char *str);
void	free_graph(t_graph *g);
void	free_all(t_list *p, t_graph *g, t_ant *ants);
void	print_paths(t_list *p);
void	print_names(t_vertex *v, t_graph g);

/*
** Libft Additional Functions
*/

int		ft_isdigit_str(char *str);
char	*ft_strndup(const char *s, int n);
void	print_matrix(t_matrix *m, const char *type);

#endif

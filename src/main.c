/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 10:56:53 by mtan              #+#    #+#             */
/*   Updated: 2018/03/30 10:56:54 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

void	error(const char *str)
{
	ft_putendl(str);
	exit(1);
}

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

void	parse_coordinates(t_vertex *v, char *line, int i, int j)
{
	int x;
	int y;

	while (line[j] == ' ')
		j++;
	if (!ft_isdigit(line[j]))
		error("Error: forbidden co-ordinates");
	x = ft_atoi(&line[j]);
	while (ft_isdigit(line[j]))
		j++;
	while (line[j] == ' ')
		j++;
	if (!ft_isdigit(line[j]))
		error("Error: forbidden co-ordinates");
	y = ft_atoi(&line[j]);
	v[i].pos.x = x;
	v[i].pos.y = y;
}

void	parse_comment(char *line, int *ends, int *i)
{
	if (line[0] == '#' && line[1] == '#')
	{
		if (ft_strstr(line, "start") || ft_strstr(line, "end"))
		{
			(*ends)++;
			i--;
		}
	}
}

void	store_vertex(t_vertex *v, char *line, int i)
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
	parse_coordinates(v, line, i, j);
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

void	store_link(t_vertex *v, char *line)
{
	char	**tmp;
	int		x;
	int		y;
	int		j;

	tmp = ft_strsplit(line, '-');
	j = 0;
	while (!ft_strequ(tmp[0], v[j].name))
		j++;
	x = j;
	j = 0;
	while (!ft_strequ(tmp[1], v[j].name))
		j++;
	y = j;
	printf("x y: %d %d\n", x, y);
	// add_edge(v, x ,y);
	free(tmp[0]);
	free(tmp[1]);
	tmp = NULL;
	ft_putendl(line);
	free(line);
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

void	ivan_test(void)
{
	t_graph		g;
	t_list		*p;
	int			i;

	g.V = 4;
	g.nodes = malloc(sizeof(t_vertex) * g.V);
	i = -1;
	while (++i < g.V)
	{
		g.nodes[i].number = i;
		g.nodes[i].children = NULL;
	}
	add_edge(g, 0, 1);
	add_edge(g, 0, 2);
	add_edge(g, 0, 3);
	add_edge(g, 2, 0);
	add_edge(g, 2, 1);
	add_edge(g, 1, 3);
	p = find_paths(g, 2, 3);
	ft_lstdel(&p, ft_free_content);
	free_graph(g);
}

int		main(void)
{
	t_ant		ants;
	t_vertex	v[42];

	parse_input(&ants, v);
	// ivan_test();
	return (0);
}

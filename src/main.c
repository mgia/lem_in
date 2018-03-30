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

char	*parse_rooms(t_vertex *v)
{
	char		*line;
	int			start;
	int 		end;
	int			links;
	int			i;
	int			j;
	int			x;
	int			y;
	// t_vertex	*v;

	// v = *vertex;
	i = 0;
	start = 0;
	end = 0;
	links = 0;
	while (get_next_line(0, &line))
	{
		if (ft_strchr(line, '-'))
		{
			links = 1;
			break ;
		}
		else if (line[0] == '#' && line[1] == '#' && ft_strstr(line, "start"))
		{
			start = 1;
			i--;
		}
		else if (line[0] == '#' && line[1] == '#' && ft_strstr(line, "end"))
		{
			end = 1;
			i--;
		}
		else if (line[0] != '#')
		{
			j = 0;
			if (line[0] == 'L')
				error("Error: Illegal name");
			while (line[j] != ' ')
				j++;
			v[i].name = ft_strndup(line, j);
			v[i].number = i;
			v[i].children = NULL;

			// saving co-ordinates
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
			// printf("end: %s\n", &line[j]);
			y = ft_atoi(&line[j]);
			// printf("y: %d\n", y);
			v[i].pos.x = x;
			v[i].pos.y = y;
			// printf("Here: %s, %d, %d\n", v[i].name, v[i].pos.x, v[i].pos.y);
			// SETXY(v[i].pos, x, 0);
			// printf("Here: %s, %d, %d\n", v[i].name, v[i].pos.x, v[i].pos.y);
		}
		i++;
		ft_putendl(line);
		free(line);
	}
	if (!i)
		error("Error: No rooms");
	if (!start || !end)
		error("Error: No Start or End");
	v[i].number = -1;
	if (!links)
		error("Error: No Links");
	return (line);
}

void	parse_links(t_vertex *v, char *line)
{
	int x = 0;
	int y = 0;
	int j = 0;
	char **tmp;
	if (line != NULL)
	{
		ft_putendl(line);
		tmp = ft_strsplit(line, '-');
		j = 0;
		printf("tmp[0]: %s tmp[1]: %s\n", tmp[0], tmp[1]);
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
		free(line);
	}
	while (get_next_line(0, &line))
	{
		ft_putendl(line);
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
		free(line);
	}
	printf("exits\n");
}

void	parse_input(t_ant *ants, t_vertex *v)
{
	char *line;
	parse_ants(ants);
	line = parse_rooms(v);
	parse_links(v, line);
}

void	ivan_test(void)
{
	t_graph		g;
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
	find_paths(g, 2, 3);
}

int		main(void)
{
	t_ant		ants;
	t_vertex	v[42];

	parse_input(&ants, v);
	// ivan_test();
	return (0);
}

#include "lem_in.h"
#include "libft.h"

/*
** 2: NO_START, 3: NO_ROOM, 4: ILLEGAL_NAME, 5: NO_PATH, 6: INVALID_ROOM
*/

void	error(const char *str)
{
	// if (i == 0)
	// 	ft_putendl("Error : No or empty file");
	// else if (i == 1)
	// 	ft_putendl("Error : invalid ants format");
	// else if (i == 2)
	// 	ft_putendl("Error : no start or end");
	// else if (i == 3)
	// 	ft_putendl("Error : no rooms");
	// else if (i == 4)
	// 	ft_putendl("Error : Illegal name");
	// else if (i == 5)
	// 	ft_putendl("Error : no path");
	// else if (i == 6)
	// 	ft_putendl("Error : invalid room");
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

// array of structs

void	parse_rooms(t_vertex *v)
{
	char	*line;
	int		start;
	int 	end;
	int		links;
	int		i;
	int		j;

	i = 0;
	j = 0;
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
			v[i].type = 1;
			i--;
		}
		else if (line[0] == '#' && line[1] == '#' && ft_strstr(line, "end"))
		{
			end = 1;
			v[i].type = 2;
			i--;
		}
		else
		{
			v[i].type = 0;
			if (line[0] == 'L')
				error("Error: Illegal name");
			while (line[j] != ' ')
				j++;
			v[i].name = ft_strndup(line, j);
		}
		i++;
		ft_putendl(line);
		free(line);
	}
	if (!i)
		error("Error: No rooms");
	if (!start || !end)
		error("Error: No Start or End");
	if (!links)
		error("Error: No Links");
}

void	parse_input(t_ant *ants, t_vertex *v)
{
	parse_ants(ants);
	parse_rooms(v);
}

void	ivan_test(void)
{
	t_vertex	g[5];
	int			i;

	i = -1;
	while (++i < 4)
	{
		g[i].number = i;
		g[i].children = NULL;
	}
	g[4].number = -1;
	add_edge(g, 0, 1);
	add_edge(g, 0, 2);
	add_edge(g, 0, 3);
	add_edge(g, 2, 0);
	add_edge(g, 2, 1);
	add_edge(g, 1, 3);
	print_paths(g, 2, 3);
}

int		main(void)
{
	t_ant		ants;
	t_vertex	v[42];

	parse_input(&ants, v);
	// ivan_test();
	return (0);
}

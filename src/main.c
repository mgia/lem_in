#include "lem_in.h"
#include "libft.h"
#include "matrix.h"
/*
** 2: NO_START, 3: NO_ROOM, 4: ILLEGAL_NAME, 5: NO_PATH, 6: INVALID_ROOM
*/

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

void	parse_rooms(t_vertex *v)
{
	char		*line;
	int			start;
	int 		end;
	int			links;
	int			i;
	int			j;
	t_matrix	matrix;
	int			k;
	int			l;

	i = 0;
	j = 0;
	k = 0;
	l = 0;
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
		else if (line[0] != '#')
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
	else
	{
		ft_putendl(line);
		matrix.rows = i;
		matrix.cols = i;
		matrix.m = malloc(sizeof(int*) * i);
		while (k < i)
		{
			matrix.m[k] = malloc(sizeof(int) * i);
			while (l < i)
			{
				MTX_TOINT(matrix.m)[k][l] = 0;
				l++;
			}
			l = 0;
			k++;
		}

		print_matrix(&matrix, "int");
	}
}

void	parse_input(t_ant *ants, t_vertex *v)
{
	parse_ants(ants);
	parse_rooms(v);
}

int		main(void)
{
	t_ant		ants;
	t_vertex	v[42];

	parse_input(&ants, v);
	return (0);
}

#include "lem_in.h"
#include "libft.h"

/*
** 2: NO_START, 3: NO_ROOM, 4: ILLEGAL_NAME, 5: NO_PATH, 6: INVALID_ROOM
*/

void	error(int i)
{
	if (i == 0)
		ft_putendl("Error : No or empty file");
	else if (i == 1)
		ft_putendl("Error : invalid ants format");
	else if (i == 2)
		ft_putendl("Error : no start or end");
	else if (i == 3)
		ft_putendl("Error : no rooms");
	else if (i == 4)
		ft_putendl("Error : Illegal name");
	else if (i == 5)
		ft_putendl("Error : no path");
	else if (i == 6)
		ft_putendl("Error : invalid room");
}

int		parse_ants(t_ant *info)
{
	char	*line;
	int		i;

	i = 0;
	if (!get_next_line(0, &line))
	{
		error(0);
		return (0);
	}
	info->number = ft_atoi(line);
	if (!ft_isdigit_str(line) || info->number <= 0)
	{
		error(1);
		return (0);
	}
	return (1);
}

int		parse_rooms(t_vertex *v)
{
	v = NULL;
	return (1);
}

int		parse_input(t_ant *ants, t_vertex *v)
{
	if (!parse_ants(ants) || !parse_rooms(v))
		return (0);
	return (1);
}

int		main(void)
{
	t_ant		ants;
	t_vertex	v;

	if (!parse_input(&ants, &v))
		return (-1);
	return (0);
}

#include "lem_in.h"
#include "libft.h"

void	error(static char *str)
{
	if (str == "NO_START")
		ft_putendl("Error : no start or end");
	else if (str == "NO_ANTS")
		ft_putendl("Error : invalid ants format");
	else if (str == "NO_ROOMS")
		ft_putendl("Error : no rooms");
	else if (str == "ILLEGAL_NAME")
		ft_putendl("Error : Illegal name");
	else if (str == "NO_FILE")
		ft_putendl("Error : No or empty file");
	else if (str == "NO_PATH")
		ft_putendl("Error : no path");
	else if (str == "INVALID_ROOM")
		ft_putendl("Error : invalid room");
}

int		main(void)
{
	// parse()
	return (0);
}

#include "libft.h"

int		ft_isdigit_str(char *str)
{
	while (str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

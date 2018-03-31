/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 14:12:13 by mtan              #+#    #+#             */
/*   Updated: 2018/03/31 14:12:16 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "matrix.h"

int		ft_isdigit_str(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

char	*ft_strndup(const char *s, size_t n)
{
	char			*res;
	unsigned int	i;

	i = 0;
	res = malloc(sizeof(char) * (n + 1));
	if (res == NULL)
		return (NULL);
	while (i < n)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

void	print_matrix(t_matrix *m, const char *type)
{
	int		i;
	int		j;

	i = -1;
	ft_printf("Matrix: %d %d ---------\n", m->rows, m->cols);
	while (++i < m->rows)
	{
		j = -1;
		while (++j < m->cols)
		{
			if (ft_strequ(type, "int"))
				ft_printf("%d ", MTX_TOINT(m->m)[i][j]);
			else if (ft_strequ(type, "char"))
				ft_printf("%d ", MTX_TOINT(m->m)[i][j]);
			else
			{
				ft_printf("usage: type int or char");
				return ;
			}
		}
		ft_printf("\n");
	}
	ft_printf("---------------------\n");
}

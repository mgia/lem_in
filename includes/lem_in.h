/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 14:00:21 by ikozlov           #+#    #+#             */
/*   Updated: 2018/03/28 14:12:59 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "math.h"

# define NO_FILE 0
# define NO_ANTS 1
# define NO_EXITS 2
# define NO_ROOMS 3
# define ILLEGAL_NAME 4
# define NO_PATH 5
# define INVALID_ROOM 6

# define REG 0
# define START 1
# define END 2

/*
** Structures
*/

struct					s_ant
{
	int					number;
	char				*location;
};
typedef struct s_ant	t_ant;

struct					s_vertex
{
	char				*name;
	int					type;
	t_point				pos;
};
typedef struct s_vertex	t_vertex;

/*
** Functions
*/

int		ft_isdigit_str(char *str);
char	*ft_strndup(const char *s, int n);

#endif

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
	t_point				pos;
	int					start;
	int					end;
};
typedef struct s_vertex	t_vertex;

/*
** Functions
*/

int		ft_isdigit_str(char *str);

#endif

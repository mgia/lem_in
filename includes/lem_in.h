/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 14:00:21 by ikozlov           #+#    #+#             */
/*   Updated: 2018/03/28 14:07:56 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

/*
** Structures
*/

struct					s_ant
{
	//a path
	int					number;
	char				*location;
};
typedef struct s_ant	t_ant;

struct					s_vertex
{
	char				*name;
	t_point				pos;
};
typedef struct s_vertex	t_vertex;

/*
** Functions
*/

#endif

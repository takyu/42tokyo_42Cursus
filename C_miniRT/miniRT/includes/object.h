/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnagoshi <tnagoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:22:54 by tnagoshi          #+#    #+#             */
/*   Updated: 2021/03/29 15:22:58 by tnagoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

typedef struct	s_object
{
	t_sphere	sp;
	t_plane		pl;
	t_square	sq;
	t_cylinder	cy;
	t_triangle	tr;
}				t_object;

// void			analyze_object();

#endif
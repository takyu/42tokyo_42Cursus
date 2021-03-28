/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnagoshi <tnagoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 19:15:54 by tnagoshi          #+#    #+#             */
/*   Updated: 2021/03/27 19:15:58 by tnagoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

typedef struct	s_cylinder
{
	double	x;
	double	y;
	double	z;
	double	dirc_x;
	double	dirc_y;
	double	dirc_z;
	double	diameter;
	double	height;
	char	r;
	char	g;
	char	b;
}				t_cylinder;

/*
** analyze_cylinder()
*/

#endif

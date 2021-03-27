/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnagoshi <tnagoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:25:14 by tnagoshi          #+#    #+#             */
/*   Updated: 2021/03/27 19:05:16 by tnagoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

typedef struct	s_camera
{
	double	x;
	double	y;
	double	z;
	double	dirc_x;
	double	dirc_y;
	double	dirc_z;
	int		fov;
}				t_camera;

/*
** analyze_camera()
*/

#endif

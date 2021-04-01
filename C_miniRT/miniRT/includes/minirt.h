/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnagoshi <tnagoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 18:19:54 by tnagoshi          #+#    #+#             */
/*   Updated: 2021/03/27 19:09:10 by tnagoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

/*
** Library header
*/
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <math.h>
# include <float.h>
# include <fcntl.h>

/*
** minilbx
*/
# include "mlx.h"

/*
** Error header
*/
# include "error.h"

/*
** Check header
*/
# include "check.h"

/*
** free header
*/
# include "free.h"

/*
** Situation header
*/
# include "resolution.h"
# include "ambient_light.h"
# include "camera.h"
# include "light.h"

/*
** Object header
*/
# include "object.h"
# include "sphere.h"
# include "plane.h"
# include "square.h"
# include "cylinder.h"
# include "triangle.h"

/*
** Strucure of status
*/
typedef struct	s_status
{
	t_resolution	*r;
	t_ambient_light	*al;
	t_camera		*c;
	t_light			*l;
	t_object		*obj;
}				t_status;

void			read_rt_file(char *name, t_status *status);

#endif

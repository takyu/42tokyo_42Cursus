/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnagoshi <tnagoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:03:40 by tnagoshi          #+#    #+#             */
/*   Updated: 2021/03/27 19:11:36 by tnagoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESOLUTION_H
# define RESOLUTION_H

typedef struct	s_resolution
{
	int		x;
	int		y;
}				t_resolution;

void			analyze_resolution(t_resolution **r, char **ps);

#endif

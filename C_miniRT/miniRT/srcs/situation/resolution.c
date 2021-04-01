/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnagoshi <tnagoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:55:28 by tnagoshi          #+#    #+#             */
/*   Updated: 2021/03/29 15:55:30 by tnagoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	analyze_resolution(t_resolution **r, char **ps)
{
	ps++;
	if (*r)
		free_status_and_error_exit();
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnagoshi <tnagoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 17:22:57 by tnagoshi          #+#    #+#             */
/*   Updated: 2021/01/26 17:14:40 by tnagoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_status(t_status *status)
{
	status->con_specifier = 0;
	status->mark_minus = -1;
	status->mark_zero = -1;
	status->accuracy = -1;
	status->width = 0;
}

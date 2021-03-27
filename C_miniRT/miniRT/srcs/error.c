/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnagoshi <tnagoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 20:04:23 by tnagoshi          #+#    #+#             */
/*   Updated: 2021/03/27 20:04:26 by tnagoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	arg_error(void)
{
	write(STDOUT_FILENO, ERROR, ft_strlen(ERROR));
	ft_putendl_fd(ERROR_ARG, STDOUT_FILENO);
	exit(1);
}

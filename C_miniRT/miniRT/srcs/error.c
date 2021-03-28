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

void	error_exit(char *s)
{
	printf("%s\n", ERROR);
	printf("%s\n", s);
	exit(1);
}

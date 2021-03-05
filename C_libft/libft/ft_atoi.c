/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnagoshi <tnagoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:49:10 by tnagoshi          #+#    #+#             */
/*   Updated: 2020/11/16 11:51:00 by tnagoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_boundary_long_min(unsigned long int res)
{
	if (res - 1 > LONG_MAX)
		return (1);
	return (0);
}

static int		is_boundary_long_max(unsigned long int res)
{
	if (res > LONG_MAX)
		return (1);
	return (0);
}

int				ft_atoi(const char *str)
{
	int					pn;
	unsigned long int	res;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	pn = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			pn *= -1;
		str++;
	}
	res = 0;
	while (*str && (*str >= '0' && *str <= '9'))
	{
		res = res * 10 + *str - '0';
		str++;
		if (pn == -1 && is_boundary_long_min(res) && res != 0)
			return (0);
		if (pn == 1 && is_boundary_long_max(res))
			return (-1);
	}
	return ((int)res * pn);
}

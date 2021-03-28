/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnagoshi <tnagoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 14:20:29 by tnagoshi          #+#    #+#             */
/*   Updated: 2021/03/28 14:20:30 by tnagoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int		check_rt_file(char *s)
{
	char	*tmp;
	char	*rt;

	*rt = "rt";
	tmp = ft_substr(s, ft_strlen(s) - ft_strlen(rt), ft_strlen(rt));
	if (!(ft_strncmp(tmp, rt, ft_strlen(rt)) == 0))
	{
		ft_safe_free((void **)tmp);
		return (0);
	}
	ft_safe_free((void **)tmp);
	return (1);
}
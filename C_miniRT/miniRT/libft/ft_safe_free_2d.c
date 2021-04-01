/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_free_2d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnagoshi <tnagoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:01:01 by tnagoshi          #+#    #+#             */
/*   Updated: 2021/03/29 15:01:02 by tnagoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_safe_free_2d(void ***p, int index)
{
	int		i;

	i = 0;
	while (i < index)
	{
		free((*p)[i]);
		(*p)[i] = NULL;
		i++;
	}
	free(*p);
	*p = NULL;
}
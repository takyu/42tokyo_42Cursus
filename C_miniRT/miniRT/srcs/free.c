/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnagoshi <tnagoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 18:49:06 by tnagoshi          #+#    #+#             */
/*   Updated: 2021/03/29 18:49:07 by tnagoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minirt.h"

void	free_status(t_status *status)
{
	ft_safe_free((void **)status->r);
	ft_safe_free((void **)status->al);
	ft_safe_free((void **)status->c);
	ft_safe_free((void **)status->l);
	ft_safe_free((void **)status->obj);
}
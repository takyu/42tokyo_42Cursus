/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnagoshi <tnagoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 11:57:58 by tnagoshi          #+#    #+#             */
/*   Updated: 2020/11/14 23:56:01 by tnagoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list		*lst_last;

	if (!new)
		return ;
	if (lst)
	{
		if (*lst)
		{
			lst_last = ft_lstlast(*lst);
			lst_last->next = new;
		}
		else
			*lst = new;
	}
}

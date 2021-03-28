/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnagoshi <tnagoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 14:16:30 by tnagoshi          #+#    #+#             */
/*   Updated: 2020/11/11 14:49:37 by tnagoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list		*lst_tmp;

	if (!del)
		return ;
	while (*lst && lst)
	{
		lst_tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = lst_tmp;
	}
}

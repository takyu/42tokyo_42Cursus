/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnagoshi <tnagoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 14:44:06 by tnagoshi          #+#    #+#             */
/*   Updated: 2020/11/18 21:49:12 by tnagoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*head;
	t_list		*new_lst;

	if (!f && !del)
		return (NULL);
	head = NULL;
	while (lst)
	{
		new_lst = ft_lstnew((*f)(lst->content));
		if (!new_lst)
		{
			while (head)
			{
				new_lst = head->next;
				(*del)(head->content);
				free(head);
				head = new_lst;
			}
			lst = NULL;
			return (lst);
		}
		ft_lstadd_back(&head, new_lst);
		lst = lst->next;
	}
	return (head);
}

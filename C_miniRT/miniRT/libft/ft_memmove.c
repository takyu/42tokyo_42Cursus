/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnagoshi <tnagoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:03:40 by tnagoshi          #+#    #+#             */
/*   Updated: 2020/11/07 17:48:28 by tnagoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		case_dst_address_large(char *dst, char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
}

static void		case_dst_address_small(char *dst, char *src, size_t len)
{
	size_t	i;

	i = len;
	while (i > 0)
	{
		i--;
		dst[i] = src[i];
	}
}

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*char_dst;
	char	*char_src;

	if (!dst && !src)
		return (NULL);
	char_dst = (char *)dst;
	char_src = (char *)src;
	if (char_dst > char_src)
		case_dst_address_small(char_dst, char_src, len);
	else
		case_dst_address_large(char_dst, char_src, len);
	return (dst);
}

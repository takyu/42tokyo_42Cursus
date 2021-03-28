/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnagoshi <tnagoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:01:51 by tnagoshi          #+#    #+#             */
/*   Updated: 2020/11/05 14:15:47 by tnagoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*char_dst;
	unsigned char	*char_src;

	if (!dst && !src)
		return (NULL);
	char_dst = (unsigned char *)dst;
	char_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		char_dst[i] = char_src[i];
		i++;
	}
	return (char_dst);
}

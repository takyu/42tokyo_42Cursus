/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnagoshi <tnagoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:56:44 by tnagoshi          #+#    #+#             */
/*   Updated: 2020/11/05 14:16:22 by tnagoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*char_dst;
	unsigned char		*char_src;
	unsigned char		char_c;
	size_t				i;

	if (!dst && !src)
		return (NULL);
	char_dst = (unsigned char *)dst;
	char_src = (unsigned char *)src;
	char_c = (char)c;
	i = 0;
	while (i < n)
	{
		char_dst[i] = char_src[i];
		if (char_dst[i] == char_c)
			return (&char_dst[i + 1]);
		i++;
	}
	return (NULL);
}

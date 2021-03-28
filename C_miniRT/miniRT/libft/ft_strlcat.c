/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnagoshi <tnagoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:05:24 by tnagoshi          #+#    #+#             */
/*   Updated: 2020/11/05 14:30:12 by tnagoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	sum_length;

	if (dstsize <= ft_strlen(dst))
		return (ft_strlen(src) + dstsize);
	sum_length = ft_strlen(dst) + ft_strlen(src);
	i = 0;
	while (dst[i])
		i++;
	j = 0;
	while (j < (dstsize - i - 1) && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (sum_length);
}

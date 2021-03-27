/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnagoshi <tnagoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:13:24 by tnagoshi          #+#    #+#             */
/*   Updated: 2020/11/05 14:30:51 by tnagoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (needle[0] == '\0')
		return ((char *)haystack);
	j = 0;
	while (j < len && haystack[j])
	{
		i = 0;
		while (j < len && haystack[j] == needle[i] && haystack[j] && needle[i])
		{
			i++;
			j++;
		}
		if (needle[i] == '\0')
			return ((char *)&haystack[j - i]);
		j = j - i + 1;
	}
	return (NULL);
}

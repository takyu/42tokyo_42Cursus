/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnagoshi <tnagoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 17:04:46 by tnagoshi          #+#    #+#             */
/*   Updated: 2020/11/13 09:46:22 by tnagoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		find_same_char(char c, char const *set)
{
	int		i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	start;
	size_t	end;
	int		i;

	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)s1);
	start = 0;
	while (s1[start] && find_same_char(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (start < end && find_same_char(s1[end - 1], set))
		end--;
	if (!(res = (char *)malloc(end - start + 1)))
		return (NULL);
	i = 0;
	while (start < end)
		res[i++] = s1[start++];
	res[i] = '\0';
	return (res);
}

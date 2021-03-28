/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnagoshi <tnagoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:43:40 by tnagoshi          #+#    #+#             */
/*   Updated: 2020/11/16 11:38:43 by tnagoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	cp_len;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start || len == 0)
	{
		res = ft_calloc(1, sizeof(char));
		return (res);
	}
	cp_len = (ft_strlen(s) > len) ? len : (ft_strlen(s) - start);
	if (!(res = (char *)malloc(cp_len + 1)))
		return (NULL);
	i = 0;
	while (i < cp_len)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

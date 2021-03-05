/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnagoshi <tnagoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 12:32:23 by tnagoshi          #+#    #+#             */
/*   Updated: 2020/12/17 03:50:15 by tnagoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t		ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char		*ft_strjoin(const char *s1, const char *s2)
{
	char	*res;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	res = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	while (*s1)
		res[i++] = *s1++;
	while (*s2)
		res[i++] = *s2++;
	res[i] = '\0';
	return (res);
}

char		*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != (char)c)
	{
		if (!(*s))
			return (NULL);
		s++;
	}
	return ((char *)s);
}

char		*ft_strdup(const char *s1)
{
	char	*res;
	int		i;

	if (!s1)
		return (NULL);
	if (!(res = (char *)malloc(ft_strlen(s1) + 1)))
		return (NULL);
	i = 0;
	while (*s1)
		res[i++] = *s1++;
	res[i] = '\0';
	return (res);
}

char		*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	cp_len;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start || len == 0)
	{
		res = (char *)malloc(1);
		*res = '\0';
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

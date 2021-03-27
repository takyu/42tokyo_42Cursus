/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnagoshi <tnagoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 17:57:23 by tnagoshi          #+#    #+#             */
/*   Updated: 2020/12/17 21:15:01 by tnagoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		free_allocated_ps(char **ps)
{
	free(*ps);
	*ps = NULL;
}

static char		*ft_strndup(char *s, int start, int end)
{
	char	*res;
	int		i;

	if (!(res = (char *)malloc(end - start + 1)))
		return (NULL);
	i = 0;
	while (i + start < end)
	{
		res[i] = s[i + start];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static int		allocate_pstr_count(char *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (s[0] == '\0')
		return (count);
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			count++;
			while (s[i] == c && s[i])
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		count++;
	return (count);
}

static void		insert_ps(char **ps, char *s, char c)
{
	int		end;
	int		start;
	int		i;
	char	*tmp;

	end = 0;
	i = 0;
	tmp = *ps;
	while (s[end] == c && s[end])
		end++;
	while (s[end])
	{
		if (s[end] != c)
		{
			start = end;
			while (s[end] != c && s[end])
				end++;
			if (!(ps[i] = ft_strndup(s, start, end)))
				free_allocated_ps(&tmp);
			i++;
		}
		while (s[end] == c && s[end])
			end++;
	}
	ps[i] = NULL;
}

char			**ft_split(char const *s, char c)
{
	char	**ps;
	int		spl_count;

	if (!s)
		return (NULL);
	spl_count = allocate_pstr_count((char *)s, c);
	if (!(ps = (char **)malloc(sizeof(char *) * (spl_count + 1))))
		return (NULL);
	insert_ps(ps, (char *)s, c);
	return (ps);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnagoshi <tnagoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:10:57 by tnagoshi          #+#    #+#             */
/*   Updated: 2021/02/04 22:13:06 by tnagoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*res;
	size_t	i;

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

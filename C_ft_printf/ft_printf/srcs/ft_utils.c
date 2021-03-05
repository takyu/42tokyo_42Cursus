/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnagoshi <tnagoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 21:14:06 by tnagoshi          #+#    #+#             */
/*   Updated: 2021/01/26 17:13:09 by tnagoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar(char c)
{
	return (write(1, &c, 1));
}

char	*ft_strchr(const char *s, int c)
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

int		ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

void	ft_safe_free(void **target)
{
	free(*target);
	*target = NULL;
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

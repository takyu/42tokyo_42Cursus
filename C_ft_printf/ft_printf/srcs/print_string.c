/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnagoshi <tnagoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 22:09:59 by tnagoshi          #+#    #+#             */
/*   Updated: 2021/06/10 16:32:52 by tnagoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin(const char *s1, const char *s2)
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

char	*ft_strndup(const char *s, int len)
{
	int		i;
	char	*buf;

	buf = (char *)malloc(len + 1);
	if (!buf)
		return (NULL);
	i = 0;
	while (i < len)
	{
		buf[i] = s[i];
		i++;
	}
	buf[i] = '\0';
	return (buf);
}

int	count_len_str(char **s, t_status *status)
{
	char		*buf;
	size_t		i;
	char		*tmp;

	if ((size_t)status->width <= ft_strlen(*s))
		return ((int)ft_strlen(*s));
	buf = (char *)malloc((size_t)status->width - ft_strlen(*s) + 1);
	i = 0;
	while (i < ((size_t)status->width - ft_strlen(*s)))
	{
		if (status->mark_zero == 1)
			buf[i] = '0';
		else
			buf[i] = ' ';
		i++;
	}
	buf[i] = '\0';
	tmp = *s;
	if (status->mark_minus == 1)
		*s = ft_strjoin(*s, buf);
	else
		*s = ft_strjoin(buf, *s);
	ft_safe_free((void **)&tmp);
	ft_safe_free((void **)&buf);
	return ((int)ft_strlen(*s));
}

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	while (*s)
		write(1, s++, 1);
}

int	print_string(char *s, t_status *status)
{
	int		ret;
	char	*print_str;

	ret = 0;
	if (!s)
		s = "(null)";
	if (status->accuracy == -1 || (size_t)status->accuracy > ft_strlen(s))
		status->accuracy = ft_strlen(s);
	if (ft_strlen(s) > (size_t)status->accuracy)
		print_str = ft_strndup(s, status->accuracy);
	else
		print_str = ft_strndup(s, ft_strlen(s));
	ret = count_len_str(&print_str, status);
	ft_putstr(print_str);
	ft_safe_free((void **)&print_str);
	return (ret);
}

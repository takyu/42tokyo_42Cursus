/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnagoshi <tnagoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 20:44:21 by tnagoshi          #+#    #+#             */
/*   Updated: 2020/11/16 12:03:49 by tnagoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	unsigned char unicode[2];
	unsigned char s;

	s = (unsigned char)c;
	if (s >= 128)
	{
		unicode[0] = (192 | (s >> 6));
		unicode[1] = (128 | (63 & s));
		write(fd, unicode, 2);
	}
	else
		write(fd, &c, 1);
}

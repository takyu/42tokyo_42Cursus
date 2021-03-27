/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnagoshi <tnagoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 21:08:37 by tnagoshi          #+#    #+#             */
/*   Updated: 2020/11/11 14:09:35 by tnagoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		div_n;
	int		mod_n;
	char	c;

	if (n == INT_MIN)
	{
		write(fd, INTMIN, ft_strlen(INTMIN));
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	div_n = n / 10;
	mod_n = n % 10;
	c = mod_n + '0';
	if (div_n > 0)
		ft_putnbr_fd(div_n, fd);
	write(fd, &c, 1);
}

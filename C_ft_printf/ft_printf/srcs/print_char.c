/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnagoshi <tnagoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 22:09:39 by tnagoshi          #+#    #+#             */
/*   Updated: 2021/06/10 16:08:14 by tnagoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c, t_status *status)
{
	int		ret;

	ret = 0;
	if (status->mark_minus == 1 && status->con_specifier == '%')
		status->mark_zero = -1;
	if (status->mark_minus == 1)
		ret += ft_putchar(c);
	while (status->width-- > 1)
	{
		if (status->mark_zero == 1)
			ret += ft_putchar('0');
		else
			ret += ft_putchar(' ');
	}
	if (status->mark_minus == -1)
		ret += ft_putchar(c);
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnagoshi <tnagoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 22:11:22 by tnagoshi          #+#    #+#             */
/*   Updated: 2021/01/27 14:53:35 by tnagoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long	ft_abs(long n)
{
	return ((n < 0) ? -n : n);
}

int		count_numlen_base(long num, int base, t_status *status)
{
	int		len;

	if (status->accuracy == 0 && num == 0)
		return (0);
	len = 0;
	if (ft_abs(num) >= base)
		len += count_numlen_base(num / base, base, status);
	else
		num < 0 ? len++ : 0;
	len++;
	return (len);
}

int		put_n_char(char c, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		write(1, &c, 1);
		i++;
	}
	return (i);
}

int		putnbr_int(long n)
{
	long	div_n;
	int		mod_n;
	int		ret;
	char	c;

	ret = 0;
	mod_n = n % 10;
	c = mod_n + '0';
	div_n = n / 10;
	if (div_n > 0)
	{
		ret += putnbr_int(div_n);
		ret += ft_putchar(c);
	}
	else
		ret = ft_putchar(c);
	return (ret);
}

int		putnbr_u_int(unsigned int n, char specifier)
{
	unsigned int	div_n;
	int				mod_n;
	int				base;
	int				ret;

	base = (specifier == 'u') ? 10 : 16;
	ret = 0;
	if (specifier == 'x')
		mod_n = (n % 16 > 9) ? (n % 16 - 10) + 'a' : n % 16 + '0';
	else if (specifier == 'X')
		mod_n = (n % 16 > 9) ? (n % 16 - 10) + 'A' : n % 16 + '0';
	else
		mod_n = n % 10 + '0';
	div_n = n / base;
	if (div_n > 0)
	{
		ret += putnbr_u_int(div_n, specifier);
		ret += ft_putchar((char)mod_n);
	}
	else
		ret = ft_putchar((char)mod_n);
	return (ret);
}

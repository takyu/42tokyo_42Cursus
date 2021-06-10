/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnagoshi <tnagoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 22:09:47 by tnagoshi          #+#    #+#             */
/*   Updated: 2021/06/10 17:01:46 by tnagoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long	ft_abs(long n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	count_space_len(long num, int num_len, t_status *status)
{
	int		len;

	len = 0;
	if (num < 0)
		num_len -= 1;
	if (num_len > status->width)
		return (len);
	if (status->accuracy > num_len)
		len = status->width - status->accuracy;
	else
		len = status->width - num_len;
	if (num < 0)
		len -= 1;
	return (len);
}

int	common_set_space_zero(long n, int space, t_status *status)
{
	int		ret;

	ret = 0;
	if (status->mark_zero == -1 && status->mark_minus == -1)
		ret += put_n_char(' ', space);
	if (status->mark_zero == 1 && status->accuracy >= 0)
		ret += put_n_char(' ', space);
	if (n < 0)
		ret += ft_putchar('-');
	if (status->mark_zero == 1 && status->accuracy <= -1)
		ret += put_n_char('0', space);
	return (ret);
}

int	print_number_di(long num, t_status *status)
{
	int		ret;
	int		num_len;
	int		space_len;

	ret = 0;
	num_len = count_numlen_base((long)num, ft_strlen(C_BASE10), status);
	space_len = count_space_len((long)num, num_len, status);
	if (num == 0 && status->accuracy == 0)
	{
		ret = put_n_char(' ', space_len);
		return (ret);
	}
	ret += common_set_space_zero(num, space_len, status);
	if (num < 0)
		ret += put_n_char('0', status->accuracy - num_len + 1);
	else
		ret += put_n_char('0', status->accuracy - num_len);
	num = ft_abs(num);
	ret += putnbr_int(num);
	if (status->mark_minus == 1)
		ret += put_n_char(' ', space_len);
	return (ret);
}

int	print_number_usxcx(unsigned int num, t_status *status)
{
	int		ret;
	int		num_len;
	int		space_len;

	ret = 0;
	if (status->con_specifier == 'u')
		num_len = count_numlen_base((long)num, ft_strlen(C_BASE10), status);
	else
		num_len = count_numlen_base((long)num, ft_strlen(C_S_BASE16), status);
	space_len = count_space_len((long)num, num_len, status);
	if (num == 0 && status->accuracy == 0)
	{
		ret = put_n_char(' ', space_len);
		return (ret);
	}
	ret += common_set_space_zero((long)num, space_len, status);
	ret += put_n_char('0', status->accuracy - num_len);
	ret += putnbr_u_int(num, status->con_specifier);
	if (status->mark_minus == 1)
		ret += put_n_char(' ', space_len);
	return (ret);
}

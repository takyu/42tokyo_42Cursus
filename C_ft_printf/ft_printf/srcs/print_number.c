/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnagoshi <tnagoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 22:09:47 by tnagoshi          #+#    #+#             */
/*   Updated: 2021/01/29 13:00:28 by tnagoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		count_space_len(long num, int num_len, t_status *status)
{
	int		len;

	len = 0;
	num_len += (num < 0) ? -1 : 0;
	if (num_len > status->width)
		return (len);
	if (status->accuracy > num_len)
		len = status->width - status->accuracy;
	else
		len = status->width - num_len;
	len += (num < 0) ? -1 : 0;
	return (len);
}

int		print_number_di(long num, t_status *status)
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
	if (status->mark_zero == -1 && status->mark_minus == -1)
		ret += put_n_char(' ', space_len);
	if (status->mark_zero == 1 && status->accuracy >= 0)
		ret += put_n_char(' ', space_len);
	ret += (num < 0) ? ft_putchar('-') : 0;
	if (status->mark_zero == 1 && status->accuracy <= -1)
		ret += put_n_char('0', space_len);
	num < 0 ? (ret += put_n_char('0', status->accuracy - num_len + 1)) :
						(ret += put_n_char('0', status->accuracy - num_len));
	num = ft_abs(num);
	ret += putnbr_int(num);
	ret += (status->mark_minus == 1) ? put_n_char(' ', space_len) : 0;
	return (ret);
}

int		print_number_usxcx(unsigned int num, t_status *status)
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
	if (status->mark_zero == -1 && status->mark_minus == -1)
		ret += put_n_char(' ', space_len);
	if (status->mark_zero == 1 && status->accuracy >= -0)
		ret += put_n_char(' ', space_len);
	if (status->mark_zero == 1 && status->accuracy <= -1)
		ret += put_n_char('0', space_len);
	ret += put_n_char('0', status->accuracy - num_len);
	ret += putnbr_u_int(num, status->con_specifier);
	ret += (status->mark_minus == 1) ? put_n_char(' ', space_len) : 0;
	return (ret);
}

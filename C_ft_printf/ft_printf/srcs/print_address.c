/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnagoshi <tnagoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 08:04:54 by tnagoshi          #+#    #+#             */
/*   Updated: 2021/01/30 22:28:52 by tnagoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		count_address_len(uintptr_t ad, int accuracy)
{
	int		len;

	len = 2;
	if (ad == 0 && accuracy == 0)
		return (2);
	else if (ad == 0)
		return (3);
	else
	{
		while (ad > 0)
		{
			ad /= 16;
			len++;
		}
	}
	return (len);
}

int		putnbr_u_int_ptr(uintptr_t ad)
{
	uintptr_t	div_ad;
	int			mod_ad;
	int			ret;

	ret = 0;
	mod_ad = (ad % 16 > 9) ? (ad % 16 - 10 + 'a') : (ad % 16 + '0');
	div_ad = ad / 16;
	if (div_ad > 0)
	{
		ret += putnbr_u_int_ptr(div_ad);
		ret += ft_putchar(mod_ad);
	}
	else
		ret = ft_putchar(mod_ad);
	return (ret);
}

int		count_space_len_ad(int ad_len, t_status *status)
{
	int		len;

	len = 0;
	if (ad_len > status->width)
		return (len);
	if (status->accuracy > ad_len - 2)
		len = status->width - status->accuracy - 2;
	else
		len = status->width - ad_len;
	return (len);
}

int		case_zero_ac_and_ad(int space_len, int flag_minus)
{
	int		ret;

	ret = 0;
	if (flag_minus == 1)
	{
		ret += write(1, "0x", 2);
		ret += put_n_char(' ', space_len);
	}
	else
	{
		ret += put_n_char(' ', space_len);
		ret += write(1, "0x", 2);
	}
	return (ret);
}

int		print_address(uintptr_t ad, t_status *status)
{
	int		ret;
	int		ad_len;
	int		space_len;

	ret = 0;
	ad_len = count_address_len(ad, status->accuracy);
	space_len = count_space_len_ad(ad_len, status);
	if (status->accuracy == 0 && ad == 0)
	{
		ret = case_zero_ac_and_ad(space_len, status->mark_minus);
		return (ret);
	}
	if (status->mark_zero == -1 && status->mark_minus == -1)
		ret += put_n_char(' ', space_len);
	if (status->mark_zero == 1 && status->accuracy >= 0)
		ret += put_n_char(' ', space_len);
	ret += write(1, "0x", 2);
	if (status->mark_zero == 1 && status->accuracy <= -1)
		ret += put_n_char('0', space_len);
	ret += put_n_char('0', status->accuracy - ad_len + 2);
	ret += putnbr_u_int_ptr(ad);
	ret += (status->mark_minus == 1) ? put_n_char(' ', space_len) : 0;
	return (ret);
}

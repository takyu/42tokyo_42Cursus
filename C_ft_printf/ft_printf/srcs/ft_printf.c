/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnagoshi <tnagoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 18:55:26 by tnagoshi          #+#    #+#             */
/*   Updated: 2021/01/30 17:18:07 by tnagoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		case_con_specifier_print(va_list ap, t_status *status)
{
	int		ret;

	ret = 0;
	if (status->con_specifier == 'c')
		ret = print_char((char)va_arg(ap, int), status);
	if (status->con_specifier == 's')
		ret = print_string((char *)va_arg(ap, char *), status);
	if (status->con_specifier == 'p')
		ret = print_address((uintptr_t)va_arg(ap, void*), status);
	if (status->con_specifier == 'd' || status->con_specifier == 'i')
		ret = print_number_di((int)va_arg(ap, int), status);
	if (status->con_specifier == 'u' || status->con_specifier == 'x'
										|| status->con_specifier == 'X')
		ret = print_number_usxcx((unsigned int)va_arg(ap, unsigned int),
																	status);
	if (status->con_specifier == '%')
		ret = print_char('%', status);
	return (ret);
}

void	set_width_and_accuracy(va_list ap, char *format, t_status *status)
{
	if (*format == '*')
	{
		if (status->accuracy == -1)
		{
			status->width = (int)va_arg(ap, int);
			if (status->width <= -1)
			{
				status->mark_minus = 1;
				status->width *= -1;
			}
		}
		else
			status->accuracy = (int)va_arg(ap, int);
	}
	else
	{
		if (status->accuracy == -1)
			status->width = status->width * 10 + *format - '0';
		else
			status->accuracy = status->accuracy * 10 + *format - '0';
	}
}

void	configure_status(va_list ap, char *format, t_status *status)
{
	if (*format == '0' && status->accuracy == -1 && status->width == 0)
		status->mark_zero = 1;
	if (*format == '-')
		status->mark_minus = 1;
	if (*format == '.')
		status->accuracy = 0;
	if (ft_isdigit(*format) || *format == '*')
		set_width_and_accuracy(ap, format, status);
}

int		analyze_format(va_list ap, char *format)
{
	int			len_printed;
	t_status	*status;

	len_printed = 0;
	if (!(status = (t_status *)malloc(sizeof(t_status))))
		return (ERROR);
	while (*format)
	{
		while (*format && *format != '%')
			len_printed += ft_putchar(*format++);
		if (*format == '%')
		{
			init_status(status);
			while (*format++ && (ft_strchr(CON_SPECIFIER, *format) == NULL))
				configure_status(ap, format, status);
			if (*format)
				status->con_specifier = *format++;
			if (status->mark_minus == 1 && status->con_specifier != '%')
				status->mark_zero = -1;
			len_printed += case_con_specifier_print(ap, status);
		}
	}
	ft_safe_free((void **)&status);
	return (len_printed);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			len_printed;

	if (format == NULL)
		return (ERROR);
	va_start(ap, format);
	len_printed = analyze_format(ap, (char *)format);
	va_end(ap);
	return (len_printed);
}

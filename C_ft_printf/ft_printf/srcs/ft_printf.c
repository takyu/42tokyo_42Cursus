/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnagoshi <tnagoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 18:55:26 by tnagoshi          #+#    #+#             */
/*   Updated: 2021/06/10 15:56:36 by tnagoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	case_con_specifier_print(va_list ap, t_status *s)
{
	int		ret;

	ret = 0;
	if (s->con_specifier == 'c')
		ret = print_char((char)va_arg(ap, int), s);
	if (s->con_specifier == 's')
		ret = print_string((char *)va_arg(ap, char *), s);
	if (s->con_specifier == 'p')
		ret = print_address((uintptr_t)va_arg(ap, void *), s);
	if (s->con_specifier == 'd' || s->con_specifier == 'i')
		ret = print_number_di((int)va_arg(ap, int), s);
	if (s->con_specifier == 'u' || s->con_specifier == 'x')
		ret = print_number_usxcx((unsigned int)va_arg(ap, unsigned int), s);
	if (s->con_specifier == 'X')
		ret = print_number_usxcx((unsigned int)va_arg(ap, unsigned int), s);
	if (s->con_specifier == '%')
		ret = print_char('%', s);
	return (ret);
}

void	set_width_accuracy(va_list ap, char *format, t_status *s)
{
	if (*format == '*')
	{
		if (s->accuracy == -1)
		{
			s->width = (int)va_arg(ap, int);
			if (s->width <= -1)
			{
				s->mark_minus = 1;
				s->width *= -1;
			}
		}
		else
			s->accuracy = (int)va_arg(ap, int);
	}
	else
	{
		if (s->accuracy == -1)
			s->width = s->width * 10 + *format - '0';
		else
			s->accuracy = s->accuracy * 10 + *format - '0';
	}
}

void	configure_status(va_list ap, char *format, t_status *s)
{
	if (*format == '0' && s->accuracy == -1 && s->width == 0)
		s->mark_zero = 1;
	if (*format == '-')
		s->mark_minus = 1;
	if (*format == '.')
		s->accuracy = 0;
	if (ft_isdigit(*format) || *format == '*')
		set_width_accuracy(ap, format, s);
}

int	analyze_format(va_list ap, char *format)
{
	int			len_printed;
	t_status	*status;

	len_printed = 0;
	status = (t_status *)malloc(sizeof(t_status));
	if (!status)
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

int	ft_printf(const char *format, ...)
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

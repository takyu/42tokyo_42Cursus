/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnagoshi <tnagoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 18:55:57 by tnagoshi          #+#    #+#             */
/*   Updated: 2021/06/10 16:56:59 by tnagoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>

# define CON_SPECIFIER "cspdiuxX%"
# define ERROR -1
# define C_BASE10 "0123456789"
# define C_S_BASE16 "0123456789abcdef"
# define C_C_BASE16 "0123456789ABCDEF"

typedef struct s_status
{
	char			con_specifier;
	int				mark_minus;
	int				mark_zero;
	int				accuracy;
	int				width;
}	t_status;

/*
** ft_printf.c
*/
int					ft_printf(const char *format, ...);
int					analyze_format(va_list ap, char *format);
void				configure_status(va_list ap, char *format, t_status *s);
void				set_width_accuracy(va_list ap, char *format, t_status *s);
int					case_con_specifier_print(va_list ap, t_status *s);

/*
** ft_initialize.c
*/
void				init_status(t_status *status);

/*
** ft_utils.c
*/
int					ft_putchar(char c);
char				*ft_strchr(const char *s, int c);
int					ft_isdigit(int c);
void				ft_safe_free(void **target);
size_t				ft_strlen(const char *s);

/*
** print_char.c
*/
int					print_char(char c, t_status *status);

/*
** print_string.c
*/
int					print_string(char *s, t_status *status);
char				*ft_strndup(const char *s, int len);
int					count_len_str(char **s, t_status *status);
char				*ft_strjoin(const char *s1, const char *s2);
void				ft_putstr(char *s);

/*
** print_address.c
*/
int					print_address(uintptr_t ad, t_status *status);
int					count_address_len(uintptr_t ad, int accuracy);
int					putnbr_u_int_ptr(uintptr_t ad);
int					count_space_len_ad(int ad_len, t_status *status);
int					case_zero_ac_and_ad(int space_len, int flag_minus);

/*
** print_number.c
*/
long				ft_abs(long n);
int					count_space_len(long num, int num_len, t_status *status);
int					common_set_space_zero(long n, int space, t_status *status);
int					print_number_di(long num, t_status *status);
int					print_number_usxcx(unsigned int num, t_status *status);

/*
** print_number_utils.c
*/
int					count_numlen_base(long num, int base, t_status *status);
int					put_n_char(char c, int n);
int					putnbr_int(long n);
char				set_char(unsigned int n, char specifier);
int					putnbr_u_int(unsigned int n, char specifier);

#endif

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

# define SPECIFIER "sdx%"
# define ERROR -1

typedef struct	s_info
{
	int		width;
	int		accuracy;
	char	specifier;
}				t_info;

void	init_info(t_info *f)
{
	f->width = 0;
	f->accuracy = -1;
	f->specifier = 0;
}

void	ft_safe_free(void **p)
{
	free(*p);
	*p = NULL;
}

int		ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int		ft_putnchar(char c, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		write(1, &c, 1);
		i++;
	}
	return (i);
}

int		ft_putstr(char *s, int len)
{
	int		i;

	i = 0;
	while (s[i] && i < len)
		write(1, &s[i++], 1);
	return (i);
}

char	*ft_strchr(char *s, char c)
{
	if (!s)
		return (NULL);
	while (*s != c)
	{
		if (!(*s))
			return (NULL);
		s++;
	}
	return (s);
}

int		ft_isdigit(char c)
{
	return ('0' <= c && c <= '9');
}

int		ft_strlen(char *s)
{
	return (*s ? ft_strlen(s + 1) + 1 : 0);
}

long	ft_abs(long n)
{
	return ((n < 0) ? -n : n);
}

void	configuer_info(char c, t_info *f)
{
	if (c == '.')
		f->accuracy = 0;
	if (ft_isdigit(c))
	{
		if (f->accuracy >= 0)
			f->accuracy = f->accuracy * 10 + c - '0';
		else
			f->width = f->width * 10 + c -'0';
	}
}

int		print_string(char *s, t_info *f)
{
	int		ret;
	int		len;

	if (!s)
		s = "(null)";
	ret = 0;
	len = ft_strlen(s);
	if (f->accuracy >= 0)
		len = (len >= f->accuracy ? f->accuracy : len);
	ret += ft_putnchar(' ', f->width - len);
	ret += ft_putstr(s, len);
	return (ret);
}

int		ft_putnbr_base(long n, char specifier)
{
	int		mod_n;
	int		base;
	int		ret;
	char	c;

	ret = 0;
	base = (specifier == 'd') ? 10 : 16;
	mod_n = (specifier == 'd') ? n % 10 : n % 16;
	c = (mod_n > 9) ? (mod_n - 10 + 'a') : (mod_n + '0');
	if (n / base > 0)
	{
		ret += ft_putnbr_base(n / base, specifier);
		ret += ft_putchar(c);
	}
	else
		ret += ft_putchar(c);
	return (ret);
}

int		count_numlen_base(long n, char specifier)
{
	int		ret;
	int		base;

	ret = 0;
	base = (specifier == 'd') ? 10 : 16;
	if (ft_abs(n) >= base)
		ret += count_numlen_base(n / base, specifier);
	else
		ret += (n < 0) ? 1 : 0;
	ret++;
	return (ret);
}

int		count_spacelen(long n, int num_len, int width, int accuracy)
{
	int		ret;

	ret = 0;
	num_len += (n < 0) ? -1 : 0;
	if (num_len > width)
		return (ret);
	if (num_len < accuracy)
		ret = width - accuracy;
	else
		ret = width - num_len;
	ret += (n < 0) ? -1 : 0;
	return (ret);
}

int		print_number(long num, t_info *f)
{
	int		ret;
	int		num_len;
	int		space_len;

	ret = 0;
	if (num == 0 && f->accuracy == 0)
		num_len = 0;
	else
		num_len = count_numlen_base(num, f->specifier);
	space_len = count_spacelen(num, num_len, f->width, f->accuracy);
	if (num == 0 && f->accuracy == 0)
	{
		ret += ft_putnchar(' ', space_len);
		return (ret);
	}
	ret += ft_putnchar(' ', space_len);
	ret += (num < 0) ? ft_putchar('-') : 0;
	if (num < 0)
		ret += ft_putnchar('0', f->accuracy - num_len + 1);
	else
		ret += ft_putnchar('0', f->accuracy - num_len);
	num = ft_abs(num);
	ret += ft_putnbr_base(num, f->specifier);
	return (ret);
}
int		case_specifier_print(va_list ap, t_info *f)
{
	int		ret;

	ret = 0;
	if (f->specifier == '%')
		ret += ft_putchar('%');
	else if (f->specifier == 's')
		ret += print_string((char *)va_arg(ap, char *), f);
	else if (f->specifier == 'd')
		ret += print_number((int)va_arg(ap, int), f);
	else if (f->specifier == 'x')
		ret += print_number((unsigned int)va_arg(ap, unsigned int), f);
	return (ret);
}

int		analyze_fmt(char *fmt, va_list ap)
{
	t_info	*f;
	int		len_print;

	len_print = 0;
	f = (t_info *)malloc(sizeof(t_info));
	if (!f)
		return (ERROR);
	while (*fmt)
	{
		while (*fmt && *fmt != '%')
			len_print += ft_putchar(*fmt++);
		if (*fmt == '%')
		{
			init_info(f);
			while (*fmt++ && (ft_strchr(SPECIFIER, *fmt) == NULL))
				configuer_info(*fmt, f);
			if (*fmt)
				f->specifier = *fmt++;
			len_print += case_specifier_print(ap, f);
		}
	}
	ft_safe_free((void **)&f);
	return (len_print);
}

int		ft_printf(const char *fmt, ...)
{
	va_list		ap;
	int			len_print;

	if (!fmt)
		return (ERROR);
	va_start(ap, fmt);
	len_print = analyze_fmt((char *)fmt, ap);
	va_end(ap);
	return (len_print);
}

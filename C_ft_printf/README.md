# ft_printf

Write a function which will mimic the real printf.  
The printf function produces output according to a format as described below.
```
%[flags][Minimum field width].[accuracy][length modifier][conversion specifier]
```
This time,  
length modifier is not supported, conversion specifier is supported only "cspdiuxX%",  
and flags is supported only ’-0.\*’.  
  
For more information, you see man 3 printf.

## Detail

1. Program name
```
libftprintf.a
```

2. Prototype
```
int	ft_printf(const char *format, ...)
```

3. External functions
```
malloc, free, write, va_start, va_arg, va_copy, va_end
```

## Note

The sites that were helpful to me are as follows.  
https://www.mm2d.net/main/prog/c/printf_format-01.html  
http://linuxjm.osdn.jp/html/LDP_man-pages/man3/printf.3.html



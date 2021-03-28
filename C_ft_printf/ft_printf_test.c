/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnagoshi <tnagoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 09:28:44 by tnagoshi          #+#    #+#             */
/*   Updated: 2021/03/15 11:59:14 by tnagoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf/includes/ft_printf.h"
#include <stdlib.h>

__attribute__((destructor))
void end()
{
    system("leaks a.out");
}

int main(void)
{
	int		pointer;
	int		len_real;
	int		len_ft;
	char	*start_for_real;
	char	*start_for_ft;
	char	*str = "abcde";

	start_for_real = str;
	start_for_ft = str;
	
	printf("---------------tester実験---------------\n");
	while (*start_for_real)
	{
		printf("%c", *start_for_real++);
	}
	printf("\n");
	while (*start_for_ft)
	{
		printf("%c", *start_for_ft++);
	}
	printf("\n");
	printf("----------------------------------------\n");

	ft_printf("%.c\n", 'c');
	printf("%.c\n", 'c');
	printf("----------------------------------------\n");

	ft_printf("%d\n", 310829);
	printf("%d\n", 310829);
	printf("----------------------------------------\n");

	ft_printf("%c\n", 'a');
	printf("%c\n", 'a');
	printf("----------------------------------------\n");

	ft_printf("%.0d\n", 0);
	printf("%.0d\n", 0);
	printf("----------------------------------------\n");

	ft_printf("%.1d\n", 0);
	printf("%.1d\n", 0);
	printf("----------------------------------------\n");

	ft_printf("%.1d\n", 12334);
	printf("%.1d\n", 12334);
	printf("----------------------------------------\n");

	ft_printf("[%-010d]\n", 123);
	printf("[%-010d]\n", 123);
	printf("----------------------------------------\n");

	ft_printf("[%0-5s]\n", "abc");
	printf("[%0-5s]\n", "abc");
	printf("----------------------------------------\n");

	ft_printf("[%0.3s]\n", "abcdef");
	printf("[%0.3s]\n", "abcdef");
	printf("----------------------------------------\n");

	ft_printf("[%.6s]\n", "abc");
	printf("[%.6s]\n", "abc");
	printf("----------------------------------------\n");

	ft_printf("[%*s]\n", -10, "abc");
	printf("[%*s]\n", -10, "abc");
	printf("----------------------------------------\n");

	ft_printf("[%.6d]\n", 123);
	printf("[%.6d]\n", 123);
	printf("----------------------------------------\n");

	ft_printf("[%.6s]\n", "abc");
	printf("[%.6s]\n", "abc");
	printf("----------------------------------------\n");

	ft_printf("[%10.2d]\n", 123);
	printf("[%10.2d]\n", 123);
	printf("----------------------------------------\n");

	ft_printf("[%0d]\n", 123);
	printf("[%0d]\n", 123);
	printf("----------------------------------------\n");

	ft_printf("[%0.10s]\n", "abc");
	printf("[%0.10s]\n", "abc");
	printf("----------------------------------------\n");

	ft_printf("[%10d]\n", 123);
	printf("[%10d]\n", 123);
	printf("----------------------------------------\n");

	ft_printf("[%.10d]\n", 123);
	printf("[%.10d]\n", 123);
	printf("----------------------------------------\n");

	ft_printf("[%0.10s]\n", "abc");
	printf("[%0.10s]\n", "abc");
	printf("----------------------------------------\n");

	ft_printf("[%10.d]\n", 123);
	printf("[%10.d]\n", 123);
	printf("----------------------------------------\n");

	ft_printf("[%.10d]\n", 123);
	printf("[%.10d]\n", 123);
	printf("----------------------------------------\n");

	ft_printf("[%8.10d]\n", 123);
	printf("[%8.10d]\n", 123);
	printf("----------------------------------------\n");

	ft_printf("[%2.d]\n", 123);
	printf("[%2.d]\n", 123);
	printf("----------------------------------------\n");

	ft_printf("[%.2d]\n", 123);
	printf("[%.2d]\n", 123);
	printf("----------------------------------------\n");

	len_ft = ft_printf("%.0d", 0);
	printf("\n");
	len_real = printf("%.0d", 0);
	printf("\n");
	printf("len_ft:%d\n", len_ft);
	printf("len_real:%d\n", len_real);
	printf("----------------------------------------\n");

	ft_printf("[%d]\n", 0);
	printf("[%d]\n", 0);
	printf("----------------------------------------\n");

	ft_printf("[%-010.d]\n", 123);
	printf("[%-010.d]\n", 123);
	printf("----------------------------------------\n");

	ft_printf("[%0-10.d]\n", 123);
	printf("[%0-10.d]\n", 123);
	printf("----------------------------------------\n");

	ft_printf("[%-010d]\n", -123);
	printf("[%-010d]\n", -123);
	printf("----------------------------------------\n");

	ft_printf("[%0.10d]\n", -123);
	printf("[%0.10d]\n", -123);
	printf("----------------------------------------\n");

	ft_printf("[%010.d]\n", -123);
	printf("[%010.d]\n", -123);
	printf("----------------------------------------\n");

	ft_printf("[%.0d]\n", -123);
	printf("[%.0d]\n", -123);
	printf("----------------------------------------\n");

	printf("%");
	ft_printf("%");
	printf("\n");
	printf("----------------------------------------\n");
	
	printf("hello, %s.", "gavin");
	printf("\n");
	ft_printf("hello, %s.", "gavin");
	printf("\n");
	printf("----------------------------------------\n");

	printf("%32s", "abc");
	printf("\n");
	ft_printf("%32s", "abc");
	printf("\n");
	printf("----------------------------------------\n");
	
	len_ft = ft_printf("%10.5i", -216);
	printf("\n");
	len_real = printf("%10.5i", -216);
	printf("\n");
	printf("len_ft:%d\n", len_ft);
	printf("len_real:%d\n", len_real);
	printf("----------------------------------------\n");

	len_ft = ft_printf("%8.3i", -8473);
	printf("\n");
	len_real = printf("%8.3i", -8473);
	printf("\n");
	printf("len_ft:%d\n", len_ft);
	printf("len_real:%d\n", len_real);
	printf("----------------------------------------\n");

	ft_printf("%010s", "42tokyo");
	printf("\n");
	printf("%010s", "42tokyo");
	printf("\n");
	printf("----------------------------------------\n");

	ft_printf("%-010s", "42tokyo");
	printf("\n");
	printf("%-010s", "42tokyo");
	printf("\n");
	printf("----------------------------------------\n");
	printf("\n");
	
	printf("---------------pointer実験---------------\n");
	ft_printf("[%p]\n", &pointer);
	printf("[%p]\n", &pointer);
	printf("----------------------------------------\n");

	ft_printf("[%-15p]\n", &pointer);
	printf("[%-15p]\n", &pointer);
	printf("----------------------------------------\n");

	ft_printf("[%-.15p]\n", &pointer);
	printf("[%-.15p]\n", &pointer);
	printf("----------------------------------------\n");

	ft_printf("[%5p]\n", &pointer);
	printf("[%5p]\n", &pointer);
	printf("----------------------------------------\n");

	ft_printf("[%20.5p]\n", &pointer);
	printf("[%20.5p]\n", &pointer);
	printf("----------------------------------------\n");

	ft_printf("[%010p]\n", &pointer);
	printf("[%010p]\n", &pointer);
	printf("----------------------------------------\n");

	ft_printf("[%0.15p]\n", &pointer);
	printf("[%0.15p]\n", &pointer);
	printf("----------------------------------------\n");

	ft_printf("[%.0p]\n", &pointer);
	printf("[%.0p]\n", &pointer);
	printf("----------------------------------------\n");

	ft_printf("[%.15p]\n", &pointer);
	printf("[%.15p]\n", &pointer);
	printf("----------------------------------------\n");

	ft_printf("[%-16.p]\n", NULL);
	printf("[%-16.p]\n", NULL);
	printf("----------------------------------------\n");

	ft_printf("[%-16.d]\n", 0);
	printf("[%-16.d]\n", 0);
	printf("----------------------------------------\n");
	printf("\n");

	// len = ft_printf("%2147483647s", "string");
	
	return (0);
}
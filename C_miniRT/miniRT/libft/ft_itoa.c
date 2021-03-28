/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnagoshi <tnagoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 21:30:40 by tnagoshi          #+#    #+#             */
/*   Updated: 2020/11/10 08:48:10 by tnagoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int		count_num_length(int n, int flag_neg)
{
	int		length;

	length = 1;
	n /= 10;
	while (n)
	{
		length++;
		n /= 10;
	}
	return (length + flag_neg);
}

char			*ft_itoa(int n)
{
	char	*res;
	int		length;
	int		digit;
	int		flag_neg;

	if (n < 0)
		flag_neg = 1;
	else
		flag_neg = 0;
	length = count_num_length(n, flag_neg);
	if (!(res = malloc(length + 1)))
		return (NULL);
	res[length--] = '\0';
	while (length >= flag_neg)
	{
		digit = n % 10;
		res[length] = ft_abs(digit) + '0';
		n /= 10;
		length--;
	}
	if (flag_neg)
		res[0] = '-';
	return (res);
}

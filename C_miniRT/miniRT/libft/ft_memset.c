/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnagoshi <tnagoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:52:53 by tnagoshi          #+#    #+#             */
/*   Updated: 2020/11/05 14:20:28 by tnagoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	unsigned char	char_c;
	size_t			i;

	str = (unsigned char *)b;
	char_c = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		str[i] = char_c;
		i++;
	}
	return (b);
}

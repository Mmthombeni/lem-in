/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmthombe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 05:01:07 by mmthombe          #+#    #+#             */
/*   Updated: 2017/09/23 05:26:42 by mmthombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_dig(long n)
{
	size_t i;

	i = 1;
	if (n < 0)
		n = -n;
	while (n >= 10)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	long	j;
	size_t	count;
	char	*str;
	char	neg;

	j = n;
	neg = (j < 0 ? 1 : 0);
	count = count_dig(j);
	str = ft_strnew(count + neg);
	if (str == NULL)
		return (NULL);
	if (neg)
	{
		j = -j;
		str[0] = '-';
	}
	while (count > 0)
	{
		str[count + neg - 1] = (j % 10) + '0';
		count--;
		j /= 10;
	}
	return (str);
}

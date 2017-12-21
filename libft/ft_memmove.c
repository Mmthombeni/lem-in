/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmthombe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 23:59:51 by mmthombe          #+#    #+#             */
/*   Updated: 2017/06/23 01:52:28 by mmthombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest;
	const char	*srce;

	dest = dst;
	srce = src;
	if (dest <= srce || srce >= (dest + len))
	{
		while (len)
		{
			*dest++ = *srce++;
			len--;
		}
	}
	else
	{
		srce = srce + len - 1;
		dest = dest + len - 1;
		while (len)
		{
			*dest-- = *srce--;
			len--;
		}
	}
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmthombe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 02:58:43 by mmthombe          #+#    #+#             */
/*   Updated: 2017/06/11 15:53:41 by mmthombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*des;
	char	*srce;

	i = -1;
	des = dest;
	srce = (char *)src;
	while (++i < n)
		*(des + i) = *(srce + i);
	return (des);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmthombe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 08:46:40 by mmthombe          #+#    #+#             */
/*   Updated: 2017/09/28 22:03:52 by mmthombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*src;
	unsigned char	*dst;

	i = 0;
	dst = (unsigned char *)s1;
	src = (unsigned char *)s2;
	while (i < n && (dst[i] || src[i]))
	{
		if (dst[i] != src[i])
			return (dst[i] - src[i]);
		i++;
	}
	return (0);
}

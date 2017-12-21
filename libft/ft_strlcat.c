/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmthombe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 23:37:39 by mmthombe          #+#    #+#             */
/*   Updated: 2017/10/07 20:56:27 by mmthombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	int		src_len;
	int		dest_len;
	size_t	i;
	size_t	index;
	size_t	len;

	i = 0;
	index = 0;
	src_len = ft_strlen(src);
	len = ft_strlen(dst);
	if (size <= 0)
		return (len);
	while (dst[i] && i < size)
		i++;
	dest_len = i;
	while (src[index] && len < size - 1)
		dst[len++] = src[index++];
	dst[len] = '\0';
	return (dest_len + src_len);
}

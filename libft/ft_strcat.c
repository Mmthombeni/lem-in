/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmthombe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 18:34:08 by mmthombe          #+#    #+#             */
/*   Updated: 2017/10/01 18:34:10 by mmthombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	size_t n;
	size_t i;

	n = ft_strlen(src);
	i = 0;
	while (src[i] != '\0')
	{
		dest[n + i] = src[i];
		i++;
	}
	return (dest);
}

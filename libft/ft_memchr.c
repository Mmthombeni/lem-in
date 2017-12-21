/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmthombe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 20:18:23 by mmthombe          #+#    #+#             */
/*   Updated: 2017/06/11 17:44:23 by mmthombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	char			*str;
	char			*temp;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		if (str[i] == (char)c)
		{
			temp = &str[i];
			return (temp);
		}
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmthombe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 18:33:27 by mmthombe          #+#    #+#             */
/*   Updated: 2017/12/19 18:42:55 by mmthombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int data, size_t byte)
{
	size_t i;

	i = 0;
	while (i < byte)
	{
		*(unsigned char *)(b + i) = (unsigned char)(data);
		i++;
	}
	return (b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmthombe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 21:55:14 by mmthombe          #+#    #+#             */
/*   Updated: 2017/09/23 03:14:07 by mmthombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	i = 0;
	if ((s1 == NULL) || (s2 == NULL))
		return (0);
	while (s1[i] || s2[i])
	{
		if ((s1[i] != s2[i]) && n > i)
			return (0);
		i++;
	}
	return (1);
}

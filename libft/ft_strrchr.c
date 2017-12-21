/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmthombe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 21:22:13 by mmthombe          #+#    #+#             */
/*   Updated: 2017/06/11 12:28:08 by mmthombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*s1;

	s1 = (char *)s;
	i = ft_strlen(s1);
	while (i > 0 && s[i] != (char)c)
		i--;
	if (s1[i] == (char)c)
		return (&(s1[i]));
	return (NULL);
}

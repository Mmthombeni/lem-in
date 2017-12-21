/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmthombe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 00:48:23 by mmthombe          #+#    #+#             */
/*   Updated: 2017/10/01 01:15:01 by mmthombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*big_char;
	char	*max_char;
	size_t	little_len;

	big_char = (char *)big;
	little_len = ft_strlen(little);
	if (little_len == 0)
		return (big_char);
	max_char = big_char + (len - little_len) + 1;
	while ((*big_char != '\0') && (big_char < max_char))
	{
		if (ft_strncmp(big_char, little, little_len) == 0)
			return (big_char);
		++big_char;
	}
	return (NULL);
}

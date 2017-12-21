/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmthombe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 18:48:38 by mmthombe          #+#    #+#             */
/*   Updated: 2017/09/23 22:01:43 by mmthombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;
	size_t	len;

	start = 0;
	len = 0;
	if (s != NULL)
	{
		while (start < ft_strlen(s) && ft_isspace(s[start]))
			start++;
		end = ft_strlen(s) - 1;
		while (end > start && ft_isspace(s[end]))
			end--;
		len = end - start + 1;
	}
	return (ft_strsub(s, start, len));
}

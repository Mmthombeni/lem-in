/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmthombe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 01:01:30 by mmthombe          #+#    #+#             */
/*   Updated: 2017/10/07 21:12:06 by mmthombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_wordcount(char const *s, char *c)
{
	int		i;
	int		j;
	int		word;

	i = 0;
	j = 0;
	word = 0;
	if (ft_strstr(s, c) == NULL)
		return (1);
	while (s[i])
	{
		while (s[i] != c[0] && s[i])
		{
			j++;
			i++;
		}
		if (j != 0 && ((s[i] == c[0]) || s[i] == '\0'))
		{
			j = 0;
			word++;
		}
		if (s[i] != '\0')
			i++;
	}
	return (word);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		words;
	int		i;
	char	ch[1];

	i = 0;
	ch[0] = c;
	if (s == NULL)
		return (NULL);
	words = ft_wordcount(s, ch);
	if (!(str = (char **)malloc(sizeof(*str) * (words + 1))))
		return (NULL);
	if (s[0] == '\0')
		str[i] = ft_strsub(s, 0, ft_wordlen(s, c));
	while (words-- && s[0] != '\0')
	{
		while (*s == c && *s)
			s++;
		str[i] = ft_strsub(s, 0, ft_wordlen(s, c));
		s = s + ft_wordlen(s, c);
		i++;
	}
	str[i] = NULL;
	return (str);
}

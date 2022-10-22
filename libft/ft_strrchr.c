/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:49:17 by lgalstya          #+#    #+#             */
/*   Updated: 2022/03/24 16:21:44 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ret;

	ret = 0;
	if (c == 0)
		return ((char *)s + ft_strlen (s));
	if (c < 0 || c > 127)
		return ((char *)s);
	while (*s)
	{
		if (*s == c)
			ret = (char *)s;
		s++;
	}
	return (ret);
}

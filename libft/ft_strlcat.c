/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 12:45:06 by lgalstya          #+#    #+#             */
/*   Updated: 2022/03/26 15:27:20 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t s)
{
	size_t	ds;
	size_t	len;
	size_t	i;

	i = 0;
	ds = ft_strlen (dst);
	if (s <= ds)
		return (s + ft_strlen (src));
	len = s - ds;
	while (src[i] && i < len - 1)
	{
		dst[ds + i] = src[i];
		i++;
	}
	dst[ds + i] = '\0';
	return (ds + ft_strlen (src));
}

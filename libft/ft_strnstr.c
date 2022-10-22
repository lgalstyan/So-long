/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:12:38 by lgalstya          #+#    #+#             */
/*   Updated: 2022/03/26 15:29:31 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (to_find[0] == '\0')
		return ((char *)str);
	if (str[0] == '\0')
		return (0);
	while (str[i] && i < len && len > 0)
	{
		j = 0;
		while (str[i + j] == to_find[j] && len > i + j)
		{
			if (!(to_find[j + 1]))
				return ((char *)(str + i));
			j++;
		}
		i++;
	}
	return (0);
}

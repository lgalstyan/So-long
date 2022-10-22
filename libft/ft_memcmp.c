/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 09:37:02 by lgalstya          #+#    #+#             */
/*   Updated: 2022/03/26 15:36:58 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	j;

	j = 0;
	while (j < n)
	{
		if ((((unsigned char *)s1)[j]) != ((unsigned char *)s2)[j])
			return (((unsigned char *)s1)[j] - ((unsigned char *)s2)[j]);
		j++;
	}
	return (0);
}

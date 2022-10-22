/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:23:53 by lgalstya          #+#    #+#             */
/*   Updated: 2022/03/26 15:20:35 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	while ((s1[i] || s2[i]) && n > 0)
	{
		if (s1[i] != s2[i])
			return ((size_t)((unsigned char)s1[i] - (unsigned char)s2[i]));
		if (s1[i] == '\0')
			return ((-1) * s2[i]);
		i++;
		n--;
	}
	return (0);
}

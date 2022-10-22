/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:17:39 by lgalstya          #+#    #+#             */
/*   Updated: 2022/03/26 15:30:22 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s, char const *set)
{
	char	*res;
	size_t	start;
	size_t	i;

	start = 0;
	i = 0;
	if (set == 0 && s == 0)
		return (0);
	while (s[start] && ft_strchr (set, s[start]))
		start++;
	i = ft_strlen (s);
	while (*s && ft_strchr (set, s[i]))
		i--;
	res = ft_substr (s, start, i - start + 1);
	return (res);
}

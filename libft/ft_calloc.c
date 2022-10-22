/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:32:33 by lgalstya          #+#    #+#             */
/*   Updated: 2022/04/09 14:11:07 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t c, size_t s)
{
	void	*res;

	res = malloc (c * s);
	if (res == 0)
		return (res);
	ft_bzero (res, c * s);
	return (res);
}

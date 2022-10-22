/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:47:04 by lgalstya          #+#    #+#             */
/*   Updated: 2022/08/01 16:47:06 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_count(t_game *var)
{
	var->move++;
	write(1, "Moves = ", 9);
	ft_putnbr_fd(var->move, 1);
	write(1, "\n", 1);
}

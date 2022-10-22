/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:16:49 by lgalstya          #+#    #+#             */
/*   Updated: 2022/07/31 15:16:52 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_game *var)
{
	int	i;

	i = -1;
	while (++i < var->map_height)
		free(var->matr[i]);
	free(var->matr);
}

int	exit_game(t_game *var)
{
	mlx_destroy_image(var->mlx, var->img.img_player);
	mlx_destroy_image(var->mlx, var->img.img_coll);
	mlx_destroy_image(var->mlx, var->img.img_exit);
	mlx_destroy_image(var->mlx, var->img.img_space);
	mlx_destroy_image(var->mlx, var->img.img_wall);
	mlx_destroy_window(var->mlx, var->mlx_win);
	free_map(var);
	exit(0);
	return (0);
}

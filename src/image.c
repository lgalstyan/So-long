/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:58:15 by lgalstya          #+#    #+#             */
/*   Updated: 2022/07/26 17:59:52 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static void	set_img(t_game *map)
{
	map->img.img_height = 50;
	map->img.img_width = 50;
	map->img.img_wall = mlx_xpm_file_to_image(map->mlx, "images/wall.xpm",
			&map->img.img_width, &map->img.img_height);
	map->img.img_exit = mlx_xpm_file_to_image(map->mlx, "images/exit.xpm",
			&map->img.img_width, &map->img.img_height);
	map->img.img_space = mlx_xpm_file_to_image(map->mlx, "images/space.xpm",
			&map->img.img_width, &map->img.img_height);
	map->img.img_coll = mlx_xpm_file_to_image(map->mlx, "images/coll.xpm",
			&map->img.img_width, &map->img.img_height);
	if (map->left_right == 1)
		map->img.img_player = mlx_xpm_file_to_image(map->mlx,
				"images/p_l.xpm", &map->img.img_width, &map->img.img_height);
	else if (map->left_right == 2)
		map->img.img_player = mlx_xpm_file_to_image(map->mlx,
				"images/p_u.xpm", &map->img.img_width, &map->img.img_height);
	else if (map->left_right == 3)
		map->img.img_player = mlx_xpm_file_to_image(map->mlx, "images/p_d.xpm",
				&map->img.img_width, &map->img.img_height);
	else
		map->img.img_player = mlx_xpm_file_to_image(map->mlx, "images/p_r.xpm",
				&map->img.img_width, &map->img.img_height);
}

static void	img_to_window(t_game *game, void *nkar, int i, int j)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, nkar,
		j * game->img.img_height, i * game->img.img_width);
}

static void	selector(char c, t_game *game, int i, int j)
{
	if (c == '1')
	{
		img_to_window(game, game->img.img_wall, i, j);
	}
	else if (c == '0')
	{
		img_to_window(game, game->img.img_space, i, j);
	}
	else if (c == 'C')
	{
		img_to_window(game, game->img.img_coll, i, j);
		game->collectible += 1;
	}
	else if (c == 'P')
	{
		game->img.pos_x = j;
		game->img.pos_y = i;
		img_to_window(game, game->img.img_player, i, j);
	}
	else if (c == 'E')
	{
		img_to_window(game, game->img.img_exit, i, j);
	}
}

void	map_to_window(t_game *vars)
{
	int	i;
	int	j;

	i = 0;
	vars->collectible = 0;
	vars->map_height = ft_count_line(vars->matr);
	vars->map_width = ft_strlen(vars->matr[0]);
	set_img(vars);
	while (i < vars->map_height)
	{
		j = -1;
		while (++j < vars -> map_width)
			selector(vars->matr[i][j], vars, i, j);
		i++;
	}
}

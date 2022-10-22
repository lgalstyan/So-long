/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:42:41 by lgalstya          #+#    #+#             */
/*   Updated: 2022/08/01 15:48:20 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static void	move_a(t_game *var)
{
	var->left_right = 1;
	if (var->matr[var->img.pos_y][var->img.pos_x - 1] == 'E'
			&& var->collectible == 0)
	{
		exit_game(var);
	}
	else if (var->matr[var->img.pos_y][var->img.pos_x - 1] != 'E'
			&& var->matr[var->img.pos_y][var->img.pos_x - 1] != '1')
	{
		move_count(var);
		var->matr[var->img.pos_y][var->img.pos_x] = '0';
		var->img.pos_x--;
		var->matr[var->img.pos_y][var->img.pos_x] = 'P';
		mlx_clear_window(var->mlx, var->mlx_win);
		map_to_window(var);
	}
}

static void	move_s(t_game *var)
{
	var->left_right = 3;
	if (var->matr[var->img.pos_y + 1][var->img.pos_x] == 'E'
			&& var->collectible == 0)
	{
		exit_game(var);
	}
	else if (var->matr[var->img.pos_y + 1][var->img.pos_x] != 'E'
			&& var->matr[var->img.pos_y + 1][var->img.pos_x] != '1')
	{
		move_count(var);
		var->matr[var->img.pos_y][var->img.pos_x] = '0';
		var->img.pos_y++;
		var->matr[var->img.pos_y][var->img.pos_x] = 'P';
		mlx_clear_window(var->mlx, var->mlx_win);
		map_to_window(var);
	}
}

static void	move_d(t_game *var)
{
	var->left_right = 0;
	if (var->matr[var->img.pos_y][var->img.pos_x + 1] == 'E'
			&& var->collectible == 0)
	{
		exit_game(var);
	}
	else if (var->matr[var->img.pos_y][var->img.pos_x + 1] != 'E'
			&& var->matr[var->img.pos_y][var->img.pos_x + 1] != '1')
	{
		move_count(var);
		var->matr[var->img.pos_y][var->img.pos_x] = '0';
		var->img.pos_x++;
		var->matr[var->img.pos_y][var->img.pos_x] = 'P';
		mlx_clear_window(var->mlx, var->mlx_win);
		map_to_window(var);
	}
}

static void	move_w(t_game *var)
{
	var->left_right = 2;
	if (var->matr[var->img.pos_y - 1][var->img.pos_x] == 'E'
			&& var->collectible == 0)
	{
		exit_game(var);
	}
	else if (var->matr[var->img.pos_y - 1][var->img.pos_x] != 'E'
			&& var->matr[var->img.pos_y - 1][var->img.pos_x] != '1')
	{
		move_count(var);
		var->matr[var->img.pos_y][var->img.pos_x] = '0';
		var->img.pos_y--;
		var->matr[var->img.pos_y][var->img.pos_x] = 'P';
		mlx_clear_window(var->mlx, var->mlx_win);
		map_to_window(var);
	}
}

int	move_player(int key, t_game *var)
{
	if (key == 0 || key == 123)
	{
		move_a(var);
	}
	else if (key == 1 || key == 125)
	{
		move_s(var);
	}
	else if (key == 2 || key == 124)
	{
		move_d(var);
	}
	else if (key == 13 || key == 126)
	{
		move_w(var);
	}
	else if (key == 53)
	{
		exit_game(var);
	}
	return (0);
}

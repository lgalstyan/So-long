/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:31:58 by lgalstya          #+#    #+#             */
/*   Updated: 2022/07/26 17:41:09 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include "../libft/libft.h"
# include <mlx.h>

typedef struct s_image
{
	int		img_height;
	int		img_width;
	void	*img_wall;
	void	*img_player;
	void	*img_space;
	void	*img_coll;
	void	*img_exit;
	int		pos_x;
	int		pos_y;
}			t_image;

typedef struct s_game
{
	int		map_width;
	int		map_height;
	int		move;
	int		collectible;
	int		exit;
	int		player;
	int		left_right;
	char	**matr;
	char	*addr;
	void	*mlx;
	void	*mlx_win;
	t_image	img;
}		t_game;

void	move_count(t_game *var);

void	free_map(t_game *var);

int		exit_game(t_game *var);

int		move_player(int key, t_game *var);

void	map_to_window(t_game *map);

int		ft_count_line(char **s);

char	**read_file(char *path);

int		checking(char **matr);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 15:35:48 by lgalstya          #+#    #+#             */
/*   Updated: 2022/07/30 15:35:50 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_rectanglar(char **matr)
{
	int	i;

	i = 0;
	while (matr[i + 1])
	{
		if (ft_strlen(matr[i]) != ft_strlen(matr[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

static int	check_external(char **matr)
{
	int		i;
	t_game	map;

	i = -1;
	map.map_height = ft_count_line(matr);
	map.map_width = ft_strlen(matr[0]);
	while (++i < map.map_width)
		if (matr[0][i] != '1' || matr[map.map_height - 1][i] != '1')
			return (0);
	i = -1;
	while (++i < map.map_height)
		if (matr[i][0] != '1' || matr[i][map.map_width - 1] != '1')
			return (0);
	return (1);
}

static int	check_one_elem(char c, t_game *map)
{
	if (c == '1' || c == '0')
		return (1);
	else if (c == 'E')
	{
		map->exit += 1;
		return (1);
	}
	else if (c == 'C')
	{
		map->collectible += 1;
		return (1);
	}
	else if (c == 'P')
	{
		map->player += 1;
		return (1);
	}
	return (0);
}

static int	check_param(char **matr)
{
	int		i;
	int		j;
	t_game	map;

	map.map_height = ft_count_line(matr);
	map.map_width = ft_strlen(matr[0]);
	map.collectible = 0;
	map.exit = 0;
	map.player = 0;
	i = -1;
	while (++i < map.map_height)
	{
		j = -1;
		while (++j < map.map_width)
			if (!check_one_elem(matr[i][j], &map))
				return (0);
	}
	if (map.exit < 1 || map.collectible < 1 || map.player != 1)
		return (0);
	return (1);
}

int	checking(char **matr)
{
	if (!check_rectanglar(matr) || !check_external(matr) || !check_param(matr))
		return (0);
	return (1);
}

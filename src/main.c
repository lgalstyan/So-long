/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 14:32:02 by lgalstya          #+#    #+#             */
/*   Updated: 2022/07/10 17:05:13 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_path(char *path)
{
	int		len;
	char	*ber;

	len = ft_strlen(path) - 4;
	ber = ".ber";
	if (ft_strncmp(path + len, ber, len) == 0)
		return (1);
	return (0);
}

char	**start(char *str)
{
	char	**matr;

	if (!check_path(str))
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	matr = read_file(str);
	if (!checking(matr))
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	return (matr);
}

int	main(int argc, char **argv)
{
	t_game	vars;

	if (argc == 2)
	{
		vars.matr = start(argv[1]);
		vars.map_height = ft_count_line(vars.matr);
		vars.map_width = ft_strlen(vars.matr[0]);
		vars.mlx = mlx_init();
		vars.mlx_win = mlx_new_window(vars.mlx, 60 * vars.map_width,
				60 * vars.map_height, "So long");
		vars.move = 0;
		map_to_window(&vars);
		mlx_hook(vars.mlx_win, 2, 1L << 0, move_player, &vars);
		mlx_hook(vars.mlx_win, 17, 1L << 17, exit_game, &vars);
		mlx_loop(vars.mlx);
	}
	return (0);
}

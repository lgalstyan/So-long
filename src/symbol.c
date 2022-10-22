/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbol.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:30:52 by lgalstya          #+#    #+#             */
/*   Updated: 2022/07/26 17:31:38 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_line(char **matr)
{
	int	i;

	i = 0;
	while (matr[i])
		i++;
	return (i);
}

static void	inv_map(int x)
{
	if (x < 0)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
}

char	**read_file(char *path)
{
	char	*curr;
	char	*tmp;
	char	*str;
	char	**matr;
	int		fd;

	str = ft_strdup("");
	fd = open(path, O_RDONLY);
	inv_map(fd);
	curr = get_next_line(fd);
	while (curr)
	{
		tmp = str;
		str = ft_strjoin(tmp, curr);
		free(curr);
		free(tmp);
		curr = get_next_line(fd);
	}
	matr = ft_split(str, '\n');
	free(str);
	free(curr);
	return (matr);
}

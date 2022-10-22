/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:07:51 by lgalstya          #+#    #+#             */
/*   Updated: 2022/04/22 17:05:28 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*get_next_line(int fd)
{
	int		rd;
	int		i;
	char	c;
	char	*buffer;

	i = 0;
	rd = read(fd, &c, 1);
	buffer = (char *)malloc(1000);
	while (rd > 0)
	{
		buffer[i++] = c;
		if (c == '\n')
			break ;
		rd = read(fd, &c, 1);
	}
	if (rd == -1 || (rd == 0 && buffer[i - 1] == '\0'))
	{
		free(buffer);
		return (NULL);
	}
	buffer[i] = '\0';
	return (buffer);
}

// static char	*line_ret(char *line, int fd)
// {
// 	char	current[BUFFER_SIZE + 1];
// 	long	i;

// 	while (1)
// 	{
// 		i = read(fd, current, BUFFER_SIZE);
// 		current[i] = '\0';
// 		if (i == -1)
// 			return (0);
// 		if (!line)
// 			line = ft_strdup(current);
// 		else
// 			line = ft_strjoin(line, current);
// 		if (ft_strchr(current, '\n') || i == 0)
// 			break ;
// 	}
// 	return (line);
// }

// char	*get_next_line(int fd)
// {
// 	static char	*buff;
// 	char		*line1;
// 	char		*line2;
// 	long		len;

// 	len = 0;
// 	buff = line_ret(buff, fd);
// 	if (!buff)
// 		return (0);
// 	len = ft_strlen(buff) - ft_strlen(ft_strchr(buff, '\n')) + 1;
// 	line1 = ft_substr(buff, 0, len);
// 	line2 = buff;
// 	buff = ft_substr(buff, len, ft_strlen(buff));
// 	free(line2);
// 	return (line1);
// }

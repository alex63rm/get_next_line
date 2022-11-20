/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:04:28 by alejarod          #+#    #+#             */
/*   Updated: 2022/11/20 12:55:34 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_read_loop(int fd, char *stash, char *buf)
{
	char	*aux;
	ssize_t	read_size;

	read_size = 1;
	while (read_size > 0)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size == -1)
			return (0);
		if (read_size == 0)
			break ;
		if (!stash)
			stash = ft_strdup("");
		buf[read_size] = '\0';
		aux = stash;
		stash = ft_strjoin(aux, buf);
		free (aux);
		aux = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (stash);
}

static char	*ft_next_stash(char *line)
{
	size_t	i;
	char	*stash;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\0')
		return (0);
	stash = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*stash == '\0')
	{
		free (stash);
		stash = NULL;
	}
	line[i + 1] = '\0';
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*stash[1024];

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (0);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	line = ft_read_loop(fd, stash[fd], buf);
	free (buf);
	if (!line)
	{
		free (stash[fd]);
		stash[fd] = NULL;
		return (0);
	}
	stash[fd] = ft_next_stash(line);
	return (line);
}

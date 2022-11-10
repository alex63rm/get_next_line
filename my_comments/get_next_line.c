/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:30:17 by alejarod          #+#    #+#             */
/*   Updated: 2022/11/10 23:49:05 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// read the file
char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*stash;

	//printf("fd is: %d\n", fd);
	if (fd < 0)
		return (NULL);
	// allocate
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	//printf("buf before read is: %s\n", buf);
	// print the line that we read. Stopped reading at \n or '\0'.
	line = ft_read_loop(fd, buf, stash);
	if (!line)
	{
		free (stash);
		return (0);
	}

	// *** MI VERSION *** si no funciona, seguir con johnh ft_extract_line)
	// update the stash for the next function call
	// SEGUIR AQUI
	stash = ft_strchr(line, '\n');
	// return the line
	return (line);
}

char	*ft_read_loop(int fd, char *buf, char *stash)
{
	char	*aux;
	ssize_t	read_size;
	// ititialize to 1 to enter the loo the first time
	read_size = 1;
	// keep reading the file. read_size is > 0 until the end
	while (read_size > 0)
	{
		// load in buf the chars read from the file
		read_size = read(fd, buf, BUFFER_SIZE);
		printf("read_size is: %zd\n", read_size);
		if (read_size == -1)
			return (0);
		// special case: reached the EOF
		if (read_size == 0)
			break;
		// end the buf with \0 to pass it as a string to strjoin
		buf[read_size] = '\0';
		// stash is empty the first time, so we initialize it to null
		if(!stash)
			stash = ft_strdup(""); // alt: stash = NULL;
		// printf("initialized stash is: %s\n", stash);
		// to update and add more bufs to the stash, I need to create an aux
		aux = stash;
		stash = ft_strjoin(aux, buf);
		// stop the loop if there is a \n or a \0 (end of file)
		//another option: if (ft_strchr(buf, '\n', if it returns sth it means it found the char, otherwise return null))
		if (ft_search_char(stash, '\n') == 1 || ft_search_char(stash, '\0'))
			break;
	}
	return (stash);
}

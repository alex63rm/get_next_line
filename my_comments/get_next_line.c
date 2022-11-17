/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:30:17 by alejarod          #+#    #+#             */
/*   Updated: 2022/11/17 19:38:48 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_loop(int fd, char *stash, char *buf)
{
	char	*aux;
	ssize_t	read_size;
	// ititialize to 1 to enter the loop the first time
	read_size = 1;
	// keep reading the file. read_size is > 0 until the end
	while (read_size > 0)
	{
		// load in buf the chars read from the file
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size == -1)
			return (0);
		// special case: reached the EOF
		if (read_size == 0)
			break;
		// stash is empty the first time, so we initialize it to null. Alt: stash = NULL.
		if(!stash)
			//stash = (char *)malloc(sizeof(char) * 1);
			stash = ft_strdup("");
		// the stash has a fixed size, so I cannot concatenate the buf.
		// create an aux to copy stash (it is an address so I equal it), then join aux and buf
		// luego stash = aux
		// end the buf with \0 to pass it as a string to strjoin
		buf[read_size] = '\0';
		aux = stash;
		stash = ft_strjoin(aux, buf);
		free (aux);
		aux = NULL;
		/* by definition it returns a pointer if it finds the char or '\0'.
		Otherwise it returns NULL and the loop continues. */
		if (ft_strchr(buf, '\n'))
			break;
	}
	return (stash);
}

// Extract the line after the \n and save the lin
static char	*ft_next_stash(char *line)
{
	size_t	i;
	char 	*stash;
	i = 0;
	// reach the position of the \n with i
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\0')
		return (0);
	// i + i to skip the \n, save the rest
	stash = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*stash == '\0')
	{
		free (stash);
		stash = NULL;
	}
	// !!! "cut" the line just after the \n by placing a \0, 
	// so that when we return it in get_next_line it is already cut 
	line[i + 1] = '\0';
	return(stash);
}

// read the file
char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	// allocate space for the read buf
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	// return the line that we read (loop until the \n that made break).
	line = ft_read_loop(fd, stash, buf);
	free (buf);
	if (!line)
	{
		free (stash);
		stash = NULL;
		return (0);
	}
	// value of stash updated after the \n
	stash = ft_next_stash(line);
	// return the first part of the line (that we "cut" with line[i + 1] = '\0')
	return (line);
}
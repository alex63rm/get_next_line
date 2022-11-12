/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:30:17 by alejarod          #+#    #+#             */
/*   Updated: 2022/11/12 14:44:53 by alejarod         ###   ########.fr       */
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
		return (0);
	// allocate space for the read buf
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	// return the line that we read (it includes before and after the \n).
	// but returns the whole buffer, it does not cut it yet
	line = ft_read_loop(fd, buf, stash);
	if (!line)
	{
		//free (stash);
		return (0);
	}
	// assign the part of the line after the \n to the next stash.
	stash = ft_next_stash(line);
	return (line);
}

char	*ft_read_loop(int fd, char *buf, char *stash)
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
		// end the buf with \0 to pass it as a string to strjoin
		buf[read_size] = '\0';
		// stash is empty the first time, so we initialize it to null. Alt: stash = NULL.
		if(!stash)
			stash = ft_strdup("");
		// to update and add more bufs to the stash, I need to create an aux
		aux = stash;
		stash = ft_strjoin(aux, buf);
		// free (aux);
		/* by definition it returns a pointer if it finds the char or '\0'.
		Otherwise it returns NULL and the loop continues. */
		if (ft_strchr(buf, '\n'))
			break;
	}
	return (stash);
}

// Saves the value after the \n in the static
char	*ft_next_stash(char *str)
{
	size_t	i;
	char 	*next_stash;

	i = 0;
	// reach the position of the \n with i
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
		return (0);
	// i + i to skip the \n
	next_stash = ft_substr(str, i + 1, ft_strlen(str) - i);
	if (*next_stash == '\0')
		next_stash = NULL;
	// assign the null in i + 1 just in case we are at the end of line
	str[i + 1] = '\0';
	return(next_stash);
}
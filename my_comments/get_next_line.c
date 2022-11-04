/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:30:17 by alejarod          #+#    #+#             */
/*   Updated: 2022/11/04 22:13:30 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// read the file
char	*get_next_line(int fd)
{
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
	ft_read_loop(fd, buf, stash);


	return (buf);
}

char	*ft_read_loop(int fd, char *buf, char *stash)
{
	char	*aux;
	ssize_t	read_size;
	read_size = 1;
	// keep reading the file. read_size is > 0 until the end
	while (read_size > 0)
	{
		// load in buf the chars read from the file
		read_size = read(fd, buf, BUFFER_SIZE);
		printf("\nread_size is: %zd\n", read_size);
		//printf("buf after read is: %s\n", buf);
		buf[read_size] = '\0';
		// stash is empty the first time, so we initialize it to null
		if(!stash)
			stash = ft_strdup(""); // alt: stash = NULL;
		// printf("initialized stash is: %s\n", stash);
		// to update and add more bufs to the stash, I need to create an aux
		aux = stash;
		stash = ft_strjoin(aux, buf);
		// check for \n char in line (if there is no \n continue reading)
		if(ft_search_char(stash, '\n') == 1)
		{
			// return the line
			ft_return_line(stash, '\n');
			// CONTINUE HERE: Check the next line char, it is not printing it
			// get the rest of the stash and update stash value
			ft_strchr(stash, '\n');
			printf("next stash is %s\n", ft_strchr(stash, '\n'));
			// update stash value
			stash = ft_strchr(stash, '\n');

			// continue the loop
			printf("loop stop");
			return("OK");
		}

	}
	return ("read_loop_finished");
}

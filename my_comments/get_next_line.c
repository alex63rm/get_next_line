/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:30:17 by alejarod          #+#    #+#             */
/*   Updated: 2022/11/05 15:13:34 by alejarod         ###   ########.fr       */
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
		// printf("buf after read is: %s\n", buf);
		// end the buf with \0 to pass it as a string to strjoin
		buf[read_size] = '\0';
		// special case: we are near the EOF
		if (read_size == 0)
			break;
		// stash is empty the first time, so we initialize it to null
		if(!stash)
			stash = ft_strdup(""); // alt: stash = NULL;
		// printf("initialized stash is: %s\n", stash);
		// to update and add more bufs to the stash, I need to create an aux
		aux = stash;
		stash = ft_strjoin(aux, buf);
		// SEGUIR AQUI, el next stash está teniendo un salto de linea y por eso 
 		if(read_size < BUFFER_SIZE)
 		{
			// return stash until the end of the string
			stash = stash + 1;
			ft_return_line(stash, '\0');
			printf("final line is %s\n", ft_return_line(stash, '\0'));
			//return(stash);
		}
		// check for \n char in line (if there is no \n continue reading)
		if(ft_search_char(stash, '\n') == 1)
		{
			// return the line
			ft_return_line(stash, '\n');
			// get the rest of the stash and update stash value
			ft_strchr(stash, '\n');
			printf("next stash is %s\n", ft_strchr(stash, '\n'));
			// update stash value
			stash = ft_strchr(stash, '\n');

			// continue the loop
			//printf("READ FINISHED\n");
			//return("OK");
		}
		// check the final case, when we reach the EOF (end of file)


	}
	printf("finished reading loop\n");
	return ("read_loop_finished");
}

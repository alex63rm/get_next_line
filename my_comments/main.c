/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:29:22 by alejarod          #+#    #+#             */
/*   Updated: 2022/11/13 22:05:52 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

 int	main(void)
 {
	int	fd;
	char *str;
	// open the file
	fd = open("book.txt", O_RDONLY);
	if (fd == -1)
		return (-1);
	else
	{
		str = get_next_line(fd);
		printf("")
		// close after using
		close(fd);
		free(str);
		return (0);
	}
 }

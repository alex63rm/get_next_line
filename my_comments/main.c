/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:29:22 by alejarod          #+#    #+#             */
/*   Updated: 2022/11/12 17:03:15 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

 int	main(void)
 {
	int	fd;
	// open the file
	fd = open("book.txt", O_RDONLY);
	if (fd == -1)
		return (-1);
	else
	{
		get_next_line(fd);
		// close after using
		close(fd);
		return (0);
	}
 }

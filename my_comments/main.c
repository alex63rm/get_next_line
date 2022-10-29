/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:29:22 by alejarod          #+#    #+#             */
/*   Updated: 2022/10/29 15:48:06 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

 int	main(void)
 {
	int	fd;
	fd = open("book.txt", O_RDONLY); // with this function we open the file
	if(fd == -1)
	{
		printf("Error opening, fd: %d\n", fd);
		return(-1);
	}
	else
	{
		printf("Open OK, fd: %d\n", fd);
		printf("Main return: %s", get_next_line(fd));
		
		close(fd);  // we close the file after using it
		return(0);
	}
 }

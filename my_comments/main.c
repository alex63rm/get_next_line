/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:29:22 by alejarod          #+#    #+#             */
/*   Updated: 2022/11/12 15:07:30 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

 int	main(void)
 {
	int	fd;
	fd = open("book.txt", O_RDONLY); // with this function we open the file
	if(fd == -1)
	{
		return(-1);
	}
	else
	{
		get_next_line(fd);
		close(fd);  // we close the file after using it
		return(0);
	}
 }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:29:22 by alejarod          #+#    #+#             */
/*   Updated: 2022/10/27 22:35:42 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

 int	main(void)
 {
	int	fd;
	fd = open("book.txt", O_RDONLY); // remove before submitting
	if(fd == -1)
	{
		printf("fd result: %d\n", fd);
		return(-1);
	}
	else
	{
		printf("fd result: %d\n", fd);
		printf("%s", get_next_line(fd));
		
		close(fd);  // remove before submitting
		return(0);
	}
 }

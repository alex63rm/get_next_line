/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:29:22 by alejarod          #+#    #+#             */
/*   Updated: 2022/11/28 13:42:53 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
 int    main(void)
 {
    int fd;
    char *str;
    size_t  i;
    // open the file
    i = 1;
    fd = open("book.txt", O_RDONLY);
        str = get_next_line(fd);
        while (str)
        {
            printf("%zu: %s", i, str);
            free(str);
            str = get_next_line(fd);
            i++;
        }
        printf("%zu: %s", i, str);
        // close after using
        close(fd);
        return (0);
 }
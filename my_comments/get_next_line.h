/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:51:45 by alejarod          #+#    #+#             */
/*   Updated: 2022/10/29 16:06:16 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<fcntl.h>	//library for open
#include<unistd.h>  // library for close
#include<stdio.h>	// for printf, remove before submitting
#include<stdlib.h>	// for malloc

// it is a good practice to put it, in case it is not defined by the user. It is like the default value
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*get_next_line(int fd);
char	*ft_strdup(char *dest, char *src);
size_t	ft_strlen(char *str);
void	*ft_memchr(const void*, int c, size_t n);

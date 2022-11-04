/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:51:45 by alejarod          #+#    #+#             */
/*   Updated: 2022/11/04 21:28:30 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<fcntl.h>	//library for open
#include<unistd.h>  // library for close
#include<stdio.h>	// for printf, remove before submitting
#include<stdlib.h>	// for malloc

// it is a good practice to put it, in case it is not defined by the user. It is like the default value
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
char	*ft_read_loop(int fd, char *buf, char *stash);
char	*ft_strdup(char *src);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *dst, char *src);
int		ft_search_char(char *str, int c);
char	*ft_return_line(char *str, int c);
char	*ft_strchr(char *str, int c);

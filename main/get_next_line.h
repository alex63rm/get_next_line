/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:51:45 by alejarod          #+#    #+#             */
/*   Updated: 2022/11/20 12:54:51 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H 
# define GET_NEXT_LINE_H

# include<unistd.h>
# include<stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*get_next_line(int fd);
char	*ft_strdup(char *src);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *dst, char *src);
char	*ft_strchr(char *str, int c);
char	*ft_substr(char *str, unsigned int start, size_t len);
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:51:49 by alejarod          #+#    #+#             */
/*   Updated: 2022/10/29 16:05:48 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//This file contains the secondary functions

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while(str[i] != '\0')
		i++;
	return(i);
}

char	*ft_strdup(char *dst, char *src)
{
	size_t	i;

	i = 0;
	if(!src)
		return(NULL);
	dst = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	if(!dst)
		return(NULL);
	while(src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	return(dst);
}

void	*ft_memchr(const void*, int c, size_t n)
{
	
}

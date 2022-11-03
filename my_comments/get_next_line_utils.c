/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:51:49 by alejarod          #+#    #+#             */
/*   Updated: 2022/11/03 22:46:02 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//This file contains the secondary functions

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if(!str)
		return(0);
	while(str[i] != '\0')
		i++;
	return(i);
}

char	*ft_strdup(char *src)
{
	size_t	i;
	char	*dst;

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

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	i = 0;
	j = 0;
	// allocate memory for the joined strings 
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	//printf("ptr malloc is %s\n", ptr);
	if(!ptr)
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	//printf("ptr after s1 is: %s\n", ptr);
	//printf("s2is: %s\n", s2);
	while(s2[j])
	{
		//printf("s2 is: %c\n", s2[j]);
		ptr[i + j] = s2[j];
		j++;
	}
	ptr[i + j] = '\0';
	printf("stash value AFTER JOIN is: %s\n", ptr);
	return(ptr);
}

int	ft_search_char(char *str, int c)
{
	size_t	i;
	i = 0;
	
/* 	if(!str)
		return(NULL); */
	while (str[i])
	{
		if(str[i] == c)
			return(1);
		i++;
	}
	return (0);	
}

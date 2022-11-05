/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:51:49 by alejarod          #+#    #+#             */
/*   Updated: 2022/11/05 15:13:10 by alejarod         ###   ########.fr       */
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
	printf("stash AFTER strjoin: %s\n", ptr);
	return(ptr);
}

// checks whether there is a character inside a string
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
// this function prints the line inside the stash up to the \n
char	*ft_return_line(char *str, int c)
{
	char	*print;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if(!str)
		return(NULL);
	// calculate the length of string until the first \n
	while (str[j] != c)
		j++;
	// allocate memory for the string to return
	print = (char *)malloc(sizeof(char) * j + 1);
	if(!print)
		return(NULL);
	// copy up to \n to a new string
	while (str[i] != c)
	{
		print[i] = str[i];
		i++;
	}
	if (str[i] == c)
		print[i] = str[i];
	print[i] = '\0';
	printf("ft_return_line result: %s\n", print);
	return(print);
}

// copies the part of the stash after the \n
char	*ft_strchr(char *str, int c)
{
	size_t	i;

	i = 0;
	while(str[i])
	{
		if (str[i] == c)
			// add 1 to the position in order to skip the first \n
			return(str + (i + 1));
		i++;
	}
	if(c == '\0')
		return(str + (i + 1));
	return (NULL);
}

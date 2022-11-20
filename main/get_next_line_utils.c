/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:51:49 by alejarod          #+#    #+#             */
/*   Updated: 2022/11/20 12:55:40 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	size_t	i;
	char	*dst;

	i = 0;
	if (!src)
		return (0);
	dst = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!dst)
		return (0);
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (0);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		ptr[i + j] = s2[j];
		j++;
	}
	ptr[i + j] = '\0';
	return (ptr);
}

char	*ft_strchr(char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (str);
		i++;
	}
	if (c == '\0')
		return (str);
	return (NULL);
}

char	*ft_substr(char *str, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	if (start > ft_strlen(str))
		return (NULL);
	if (len > ft_strlen(str))
		len = ft_strlen(str);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	while (str[start] && i < len)
	{
		ptr[i] = str[start];
		start++;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

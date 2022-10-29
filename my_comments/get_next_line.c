/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:50:13 by alejarod          #+#    #+#             */
/*   Updated: 2022/10/29 16:56:37 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Description: The function returns a line read from a file descriptor
• Consideramos que get_next_line tiene un comportamiento indefinido si, entre
llamadas, el mismo fd cambia de archivo antes de terminar la lectura sobre el
primer fd.
• Finalmente, consideramos que get_next_line tiene un comportamiento indefinido
si se lee un binario. Sin embargo, y si así lo deseas, puedes dar coherencia a este
comportamiento.
• Las variables globales están prohibidas.
• Importante: la línea devuelta debe incluir el ’\n’, excepto si has llegado al final del
archivo y no hay ’\n’.
*/
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	ssize_t		read_size;
	char		*buf;
	static char	*saved;
	size_t		i;
	
	//1.2. Allocate memory in the heap for the characters read
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if(!buf)
		return(NULL);
	//1.1. read the fd, for which I need to allocate space for buf with malloc (1.2)
	read_size = read(fd, buf, BUFFER_SIZE);
	printf("read_size is: %zd\n", read_size);
	if(read_size < 0)
		return(NULL);
	// 2.1. Add the buf read data to a static saved string
	// 2.2. Save the return of strdup in saved
	saved = ft_strdup(saved, buf);
	printf("(saved) static var content: %s\n", saved);
	// 3. Check if the buf read more than a line
	i = 0;
	while(saved[i] != '\0')
	{
		if(saved[i] == '\n')
		{
			//if there was a line, we can return it
			//we need to save the rest to join it with the next buffer
			
			
		}	
		//if no \n we can print the whole line

		if there is a null, it means the text is over (mem)

		if there is a \n, just we need to return up to \n 
		and then keep the rest (memchr) to join (strjoin) with the next
		i++;
	}
	next_line = ft_memchr(buf, '\n', ft_strlen(buf));
	if() */
	//leer
	
	return(buf);
	free(buf);
}

int read_size;

read_size = 1;
mientras(statica no encunetre salto de linea o mientras halla algo que leer)
{
	leemos y asignamos la cantidad de bytes leidos.(read_size = read)
	if (read_size es cero o menos uno)
	{
		liberar buff
		(si sigues teniendo leaks liberar el otro)
		retornnar null
	}
	buff[read_size] == '\0';
	actualizar la estatica añadiendo el nuevo contenido de buff
}
char	*get_next_line(int fd)
{
	static char	*save;
	char		*buf;
	
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if(!buf)
		return(NULL);
	
	save = ft_read(fd, buf, BUFFER_SIZE, 1);
}

int	ft_search_char(char *str, int c)
{
	int	i;

	i = -1;
	if(!str)
		return(0);
	while (str[++i])
	{
		if(str[i] == c)
			return(1);
	}
	return (0);
}

char *ft_read(int fd, char *buf, int buffer_size, ssize_t read_size)
{	
	//si no encuentra salto de linea en la estatica  o mientras halla algo que leer
	while (ft_search_char(save, '\n') == 0 && read_size > 0)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		buf[read_size] = '\0';
	}
}

read_size = read(fd, buf, BUFFER_SIZE);



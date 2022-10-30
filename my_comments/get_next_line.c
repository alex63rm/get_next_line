/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:50:13 by alejarod          #+#    #+#             */
/*   Updated: 2022/10/30 22:55:13 by alejarod         ###   ########.fr       */
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

static char	*ft_updated_saved(char *saved, char *buf);
int			ft_search_char(char *str, int c);
char		*ft_read(int fd, char *buf, char *saved);
char		*ft_cut_saved(char *saved);

char	*get_next_line(int fd)
{
	printf("FT_GNL\n");
	static char	*saved;
	char		*buf;
	// check for errors in opening the file or if buffer_size is negative
	if (fd < 0 || BUFFER_SIZE <= 0)
		return(NULL);
	// allocate memory for the read bytes
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if(!buf)
		return(NULL);
	// the static variable keeps the read bytes
	saved = ft_read(fd, buf, saved);
	printf("saved before cutting is: %s\n", saved);
	free(buf);
	if (ft_search_char(saved, '\n') == 1)
	{
		ft_cut_saved(saved);
/* 		//ya he cortado saved, ahora tengo que coger el resto de saved hasta el siguiente salto y unirlo hasta el siguiente salto, siguiente ronda.
		borrar  el primer cacho de saved*/
	}
	return(saved);
}
/* char	*ft_join_line()
{
	
}
 */

////////// seguir aqui	/////////////////


// ya he cortado, ahora tengo que unir lo que haya en static con la siguiente lectura hasta que 



// return the first line, up to the first \n
char	*ft_cut_saved(char *saved)
{
	char		*cut_saved;
	size_t		i;
	size_t		j;

	// calculate lenght of cut_saved
	i = 0;
	while (saved[i] != '\n')
		i++;
	printf("size of first line: %zu\n", i);
	// allocate memory for cut_saved
	cut_saved = (char *)malloc((sizeof(char) * i) + 1);
	if (!cut_saved)
		return (NULL);
	// write to cut_saved
	j = 0;
	while (saved[j] != '\n')
	{
		cut_saved[j] = saved[j];
		j++;
	}
	cut_saved[j] = '\0';
	printf("cut saved: %s\n", cut_saved);
	return (cut_saved);
}


// check if there is a \n in a string
int	ft_search_char(char *str, int c)
{
	printf("FT_SEARCH_CHAR\n");
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

// read from file and save it to the static variable
char	*ft_read(int fd, char *buf, char *saved)
{	
	printf("FT_READ\n");
	ssize_t	read_size;
	int		new_line_char;
	int		i = 0;

	new_line_char = ft_search_char(saved, '\n');
	// keep reading and increase the size of the static
	while (new_line_char == 0)	// NO ENTIENDO EL MOTIVO DE ESTA CONDICION!!!!!!!!!!!!!!!!!!!
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		// -1 means error reading the file, 0 means there are no more bytes left to read
		if(read_size <= 0)
			break;
		buf[read_size] = '\0';
		// update the lenght of the static saved 
		saved = ft_updated_saved(saved, buf);
		i++;
	}
	// if the buffer size is big and contains new lines, save everything in the static
	return (saved);
}
// concatenate old static saved with the new bufer, creating a new save with malloc
static char	*ft_updated_saved(char *saved, char *buf)
{
	printf("FT_UPDATED_SAVED\n");
	char	*new_saved;
	size_t	i;
	size_t	j;
	
	i = 0;
	j = 0;
	// allocate memory to join old saved with the new buf (making saved bigger every time)
	new_saved = (char *)malloc(sizeof(char) * (ft_strlen(saved) + ft_strlen(buf)) + 1);
	if (!new_saved)
		return (NULL);
	// new saved = saved + buf
	if (saved != NULL)
	{
		while (saved[i] != '\0')
		{
			new_saved[i] = saved[i];
			i++;
		}
	}
	while (buf[j] != '\0')
	{
		new_saved[i] = buf[j];
		i++;
		j++;
	}
	new_saved[i] = '\0';
	return(new_saved);
}

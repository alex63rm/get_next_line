/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:50:13 by alejarod          #+#    #+#             */
/*   Updated: 2022/10/26 21:11:35 by alejarod         ###   ########.fr       */
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
char *get_next_line(int fd)
{

}
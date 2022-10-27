/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:51:45 by alejarod          #+#    #+#             */
/*   Updated: 2022/10/27 22:30:49 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<fcntl.h>	//library for open
#include<unistd.h>  // library for close
#include<stdio.h>	//for printf, remove before submitting

char	*get_next_line(int fd);

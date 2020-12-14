/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 17:59:17 by mykman            #+#    #+#             */
/*   Updated: 2020/12/14 17:19:25 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	return ((*s == c) ? (char *)s : NULL);
}

int	get_next_line(int fd, char **line)
{
	int 		n;
	static char	*save;
	char		buf[BUFFER_SIZE + 1];

	if (fd < 0 || !line)
		return (-1);
	*line = NULL;
	while ((n = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[n] = 0;
		*line = ft_strjoin(*line, buf);
		if (ft_strchr(buf, '\n'))
		{
			*line = ft_strjoin(save, *line)
			*ft_strchr(*line, '\n') = 0;
			break;
		}
	}
	return (0);
}

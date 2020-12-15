/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.19.be>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 17:59:17 by mykman            #+#    #+#             */
/*   Updated: 2020/12/15 01:50:11 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

char	*gnl_strjoin(char *s1, char *s2, int free_char)
{
	size_t	size;
	char	*ptr;

	if (!s1)
		return (ft_strdup(s2));
	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(ptr = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_memcpy(ptr, s1, ft_strlen(s1));
	ft_memcpy(ptr + ft_strlen(s1), s2, ft_strlen(s2));
	ptr[size] = 0;
	if (free_char == 1 || free_char == 2)
		free(s1);
	if (free_char == 2)
		free(s2);
	return (ptr);
}

int		get_next_line(int fd, char **line)
{
	static char	*saved;
	char		buf[BUFFER_SIZE + 1];
	char		*tmp;
	int			n;

	*line = NULL;
	if (saved && ft_strchr(saved, '\n'))
	{
		tmp = saved;
		saved = ft_strdup(ft_strchr(saved, '\n') + 1);
		*ft_strchr(tmp, '\n') = 0;
		*line = ft_strdup(tmp);
		free(tmp);
		return (0);
	}
	while ((n = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[n] = 0;
		*line = gnl_strjoin(*line, buf, 1);
		if (ft_strchr(buf, '\n') || n < BUFFER_SIZE)
		{
			if (saved)
				*line = gnl_strjoin(saved, *line, 2);
			saved = ft_strdup(ft_strchr(buf, '\n') + 1);
			*ft_strchr(*line, '\n') = 0;
			return ((n < BUFFER_SIZE) ? 0 : 1);
		}
	}
	return (-1);
}

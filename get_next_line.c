/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 17:59:17 by mykman            #+#    #+#             */
/*   Updated: 2020/12/31 18:32:53 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

char	*gnl_strjoin(char *s1, char *s2, int free_char)
{
	size_t	size;
	char	*ptr;

	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(ptr = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_memcpy(ptr, s1, ft_strlen(s1));
	ft_memcpy(ptr + ft_strlen(s1), s2, ft_strlen(s2));
	ptr[size] = 0;
	if (s1 && (free_char == 1 || free_char == 2))
		free(s1);
	if (free_char == 2)
		free(s2);
	return (ptr);
}

/*int		get_next_line(int fd, char **line)
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
		*(ft_strchr(tmp, '\n') + 1) = 0;
		*line = ft_strdup(tmp);
		free(tmp);
		return (1);
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
			*(ft_strchr(*line, '\n') + 1) = 0;
			return ((n < BUFFER_SIZE) ? 0 : 1);
		}
	}
	return (-1);
}*/

/*int		get_next_line(int fd, char **line)
{
	static char	*saved;
	char		buf[BUFFER_SIZE + 1];
	int			bytes;

	if (!line)
		return (-1);
	if (ft_strchr(saved, '\n'))

	while ((bytes = (int)read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[bytes] = 0;
		if (!(*line = gnl_strjoin(*line, buf, 1)))
			return (-1);
		if (ft_strchr(*line, '\n'))
		{
			saved = ft_strdup(ft_strchr(*line, '\n') + 1);
			return (1);
		}
	}
	return ((bytes) ? -1 : 0);
}*/

char	*gnl_line(char *saved)
{
	char	*line;
	int		size;

	size = 0;
	while (saved[size] != '\n')
		size++;
	if ()
	return (line);
}

int		get_next_line(int fd, char **line)
{
	static char	*saved;
	char		buff[BUFFER_SIZE];
	char		*tmp;
	int			bytes;

	if (fd < 0 || !line)
		return (-1);
	while (!ft_strchr(saved, '\n'))
	{
		if ((bytes = read(fd, buff, BUFFER_SIZE)) < 0)
			return (-1);
		buff[bytes] = 0;
		if (!(saved = gnl_strjoin(saved, buff, 2))) //ATTENTION FREE si malloc foire (a faire)
			return (-1);
	}
	if (!(tmp = ft_strdup(saved[ft_strchr(saved, '\n') + 1])))
		return (-1);
	
	return (0);
}

















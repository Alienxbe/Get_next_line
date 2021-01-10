/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 00:34:22 by mykman            #+#    #+#             */
/*   Updated: 2021/01/10 10:54:03 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*gnl_strjoin(char *s1, char *s2)
{
	int		size;
	char	*ptr;

	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(ptr = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_memcpy(ptr, s1, ft_strlen(s1));
	ft_memcpy(ptr + ft_strlen(s1), s2, ft_strlen(s2));
	ptr[size] = 0;
	if (s1)
		free(s1);
	return (ptr);
}

int		get_next_line(int fd, char **line)
{
	static char	*saved[OPEN_MAX];
	char		*buff;
	int			bytes;

	if (fd < 0 || !line
		|| !(buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	bytes = 1;
	while (ft_index(saved[fd], '\n') < 0 && bytes != 0)
	{
		if ((bytes = (int)read(fd, buff, BUFFER_SIZE)) < 0)
			return (free_return(&buff, -1));
		buff[bytes] = 0;
		if (!(saved[fd] = gnl_strjoin(saved[fd], buff)))
			return (free_return(&buff, -1));
	}
	free(buff);
	if (!(*line = ft_substr(saved[fd], 0, ft_index(saved[fd], '\n'), 0)))
		return (-1);
	if (!(saved[fd] = ft_substr(saved[fd], ft_index(saved[fd], '\n') + 1,
		ft_strlen(saved[fd]) - ft_index(saved[fd], '\n'), 1)))
		return (free_return(line, -1));
	return ((bytes) ? 1 : free_return(&saved[fd], 0));
}

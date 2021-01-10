/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 00:34:22 by mykman            #+#    #+#             */
/*   Updated: 2021/01/10 10:49:49 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*saved;
	char		*buff;
	int			bytes;

	if (fd < 0 || !line
		|| !(buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	bytes = 1;
	while (ft_index(saved, '\n') < 0 && bytes != 0)
	{
		if ((bytes = (int)read(fd, buff, BUFFER_SIZE)) < 0)
			return (free_return(&buff, -1));
		buff[bytes] = 0;
		if (!(saved = gnl_strjoin(saved, buff)))
			return (free_return(&buff, -1));
	}
	free(buff);
	if (!(*line = ft_substr(saved, 0, ft_index(saved, '\n'), 0)))
		return (-1);
	if (!(saved = ft_substr(saved, ft_index(saved, '\n') + 1,
		ft_strlen(saved) - ft_index(saved, '\n'), 1)))
		return (free_return(line, -1));
	return ((bytes) ? 1 : free_return(&saved, 0));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 17:59:17 by mykman            #+#    #+#             */
/*   Updated: 2021/01/07 21:32:37 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

/*
** GNL_STRJOIN Forget first letter
*/

char	*gnl_strjoin(char *s1, char *s2, int to_free)
{
	int		size;
	char	*ptr;

	size = ((ft_index(s1, 0) < 0) ? 0 : ft_index(s1, 0)) + ft_index(s2, 0);
	if (!(ptr = (char *)malloc(sizeof(char) * (size + 1))))
	{
		free(s2);
		return (NULL);
	}
	ft_memcpy(ptr, s1, (ft_index(s1, 0) < 0) ? 0 : ft_index(s1, 0));
	ft_memcpy(ptr + ft_index(s1, 0), s2, ft_index(s2, 0));
	ptr[size] = 0;
	if (s1 && (to_free == 1 || to_free == 2))
		free(s1);
	if (to_free == 2)
		free(s2);
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
	while (ft_index(buff, '\n') < 0)
	{
		if ((bytes = read(fd, buff, BUFFER_SIZE)) < 0)
		{
			free(buff);
			return (-1);
		}
		buff[bytes] = 0;
		if (!(saved = gnl_strjoin(saved, buff, 1)))
			return (-1);
	}
	*line = saved;
	free(buff);
	return (0);
}

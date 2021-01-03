/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 17:59:17 by mykman            #+#    #+#             */
/*   Updated: 2021/01/03 20:50:38 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

char	*gnl_strjoin(char *s1, char *s2, int free_char)
{
	int		size;
	char	*ptr;

	size = ((ft_index(s1, 0) < 0) ? 0 : ft_index(s1, 0)) + ft_index(s2, 0);
	if (!(ptr = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_memcpy(ptr, s1, (ft_index(s1, 0) < 0) ? 0 : ft_index(s1, 0));
	ft_memcpy(ptr + ft_index(s1, 0), s2, ft_index(s2, 0));
	ptr[size] = 0;
	if (s1 && (free_char == 1 || free_char == 2))
		free(s1);
	if (free_char == 2)
		free(s2);
	return (ptr);
}

int		get_next_line(int fd, char **line)
{
	static char	*saved;
	char		buff[BUFFER_SIZE];
	int			bytes;

	if (fd < 0 || !line)
		return (-1);
	while (ft_index(buff, '\n') < 0)
	{
		if ((bytes = read(fd, buff, BUFFER_SIZE)) < 0)
			return (-1);
		buff[bytes] = 0;
		printf("%s\n", buff);
		if (!(saved = gnl_strjoin(saved, buff, 1))) //ATTENTION FREE si malloc foire (a faire)
			return (-1);
	}
	if (!(*line = ft_substr(saved, 0, ft_index(saved, '\n'))))
		return (-1);
	/*if (!(saved = ft_substr(saved, ft_index(saved, '\n') + 1, ft_index(saved, 0) - ft_index(saved, '\n') + 1)))
		return (-1);*/
	printf("%s || %s\n", *line, saved);
	return (0);
}

















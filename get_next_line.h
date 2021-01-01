/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 17:59:20 by mykman            #+#    #+#             */
/*   Updated: 2021/01/01 16:12:53 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include <unistd.h>
#include <stdlib.h>

int	get_next_line(int fd, char **line);

/*
** --- Utils ---
*/

char	*gnl_strjoin(char *s1, char *s2, int free_char);
int		ft_strlen(const char *s);
char	*ft_strchr(char *s, char c);
char	*gnl_strldup(const char *s, int size);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif
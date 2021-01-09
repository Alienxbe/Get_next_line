/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 17:59:20 by mykman            #+#    #+#             */
/*   Updated: 2021/01/09 00:58:51 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

/*
** --- Main ---
*/

int		get_next_line(int fd, char **line);
char	*gnl_strjoin(char *s1, char *s2);

/*
** --- Utils ---
*/

int		ft_index(const char *str, char c);
char	*ft_substr(const char *s, int start, int l);
void	*ft_memcpy(void *dest, const void *src, int n);

#endif
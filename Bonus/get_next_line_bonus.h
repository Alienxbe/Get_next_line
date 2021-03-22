/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 17:59:20 by mykman            #+#    #+#             */
/*   Updated: 2021/03/22 20:27:48 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

/*
** --- Main ---
*/

int		get_next_line(int fd, char **line);
char	*gnl_strjoin(char *s1, char *s2);

/*
** --- Utils ---
*/

int		free_return(char **str, int ret_value);
int		ft_index(char *str, char c);
int		ft_strlen(char *s);
char	*ft_substr(char *s, int start, int len, int s_free);
void	*ft_memcpy(void *dest, void *src, int n);

#endif

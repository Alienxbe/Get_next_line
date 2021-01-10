/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 17:59:29 by mykman            #+#    #+#             */
/*   Updated: 2021/01/10 10:54:09 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		free_return(char **str, int ret_value)
{
	free(*str);
	*str = NULL;
	return (ret_value);
}

int		ft_index(char *s, char c)
{
	int i;

	if (!s)
		return (-1);
	i = -1;
	while (s[++i])
		if (s[i] == c)
			return (i);
	return ((s[i] == c) ? i : -1);
}

int		ft_strlen(char *s)
{
	return ((s) ? ft_index(s, 0) : 0);
}

void	*ft_memcpy(void *dest, void *src, int n)
{
	if (!dest && !src)
		return (0);
	while (n--)
		*((unsigned char *)dest + n) = *((unsigned char *)src + n);
	return (dest);
}

char	*ft_substr(char *s, int start, int len, int s_free)
{
	char	*p;

	len = (len < 0) ? ft_strlen(s) : len;
	if ((p = (char *)malloc(sizeof(*p) * (len + 1))))
	{
		p[len] = 0;
		ft_memcpy(p, s + start, len);
	}
	if (s_free || !p)
		free(s);
	return ((p) ? p : NULL);
}
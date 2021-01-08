/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 17:59:29 by mykman            #+#    #+#             */
/*   Updated: 2021/01/08 00:17:35 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_index(const char *s, char c)
{
	int i;

	if (!s)
		return (0);
	i = -1;
	while (s[++i])
		if (s[i] == c)
			return (i);
	return ((s[i] == c) ? i : -1);
}

char	*ft_substr(const char *s, int start, int len)
{
	char	*p;

	if (start > ft_index(s, 0)
		|| !(p = (char *)malloc(sizeof(*p) * (len + 1))))
		return (NULL);
	p[len + 1] = 0;
	return (ft_memcpy(p, s + start, len));
}

void	*ft_memcpy(void *dest, const void *src, int n)
{
	if (!dest && !src)
		return (0);
	while (n--)
		*((unsigned char *)dest + n) = *((unsigned char *)src + n);
	return (dest);
}

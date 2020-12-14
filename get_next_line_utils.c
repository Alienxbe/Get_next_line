/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 17:59:29 by mykman            #+#    #+#             */
/*   Updated: 2020/12/14 16:35:35 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	i;

	if (!(ptr = (char *)malloc(nmemb * size)))
		return (NULL);
	i = 0;
	while (i < nmemb * size)
		ptr[i++] = 0;
	return ((void *)ptr);
}

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*ptr;

	size = (size_t)(ft_strlen(s) + 1);
	if (!(ptr = malloc(sizeof(*ptr) * size)))
		return (NULL);
	return (ft_memcpy(ptr, s, size));
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	if (!dest && !src)
		return (0);
	while (n--)
		*((unsigned char *)dest + n) = *((unsigned char *)src + n);
	return (dest);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	size;
	char	*ptr;

	if (!s1)
		return (ft_strdup(s2));
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(ptr = (char *)ft_calloc(sizeof(*ptr), size)))
		return (NULL);
	ft_memcpy(ptr, s1, ft_strlen(s1));
	ft_memcpy(ptr + ft_strlen(s1), s2, ft_strlen(s2));
	free((void *)s1);
	return (ptr);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 18:01:52 by mykman            #+#    #+#             */
/*   Updated: 2021/01/01 16:18:47 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

void	add(char *str)
{
	static char	*a;

	if (!a)
		printf("First occurence\n");
	else
		printf("last occurence was : %s\n", a);
	a = str;
}

int main(void)
{
	int		fd;
	char	*str = NULL;

	if ((fd = open("test.txt", O_RDONLY)) < 0)
		return (1);
	printf("%d : %s\n", get_next_line(fd, &str), str);
	if ((close(fd)) < 0)
		return (1);
	return (0);
}

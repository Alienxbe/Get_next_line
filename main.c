/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 00:34:22 by mykman            #+#    #+#             */
/*   Updated: 2021/01/08 01:04:35 by mykman           ###   ########.fr       */
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
	char *str = "la base";
	printf("%s\n", str);
	get_next_line(10, &str);
	printf("%s\n", str);
/*	int		fd;
	char	*str;

	str = NULL;
	if ((fd = open("test.txt", O_RDONLY)) < 0)
		return (1);
	printf("%d : %s\n", get_next_line(fd, &str), str);
	if ((close(fd)) < 0)
		return (1);*/
	return (0);
}

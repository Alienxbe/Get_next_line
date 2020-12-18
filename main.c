/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.19.be>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 18:01:52 by mykman            #+#    #+#             */
/*   Updated: 2020/12/16 17:07:26 by mykman           ###   ########.fr       */
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
	int		out;
	char	*str = NULL;

	if ((fd = open("test.txt", O_RDONLY)) < 0)
		return (1);
	for (int i = 0; i < 10; i++)
	{
		out = get_next_line(fd, &str);
		printf("%d : %s", out, str);
		free(str);
	}
	printf("%s\n", str);
	if ((close(fd)) < 0)
		return (1);
	return (0);
}

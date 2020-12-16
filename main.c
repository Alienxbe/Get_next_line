/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.19.be>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 18:01:52 by mykman            #+#    #+#             */
/*   Updated: 2020/12/15 22:46:37 by mykman           ###   ########.fr       */
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
	//int		fd;
	char	*str = NULL;
	for (int i = 0; i < 2; i++)
	{
		get_next_line(1, &str);
		printf("Input : %s\n", str);
		free(str);
	}
	/*if ((fd = open("test.txt", O_RDONLY)) < 0)
		return (1);
	for (int i = 0; i < 5; i++)
	{
		if (get_next_line(fd, &str) == -1)
			return (1);
		printf("%s\n", str);
		free(str);
	}
	printf("%s\n", str);
	if ((close(fd)) < 0)
		return (1);*/
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.19.be>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 18:01:52 by mykman            #+#    #+#             */
/*   Updated: 2020/12/14 01:07:46 by mykman           ###   ########.fr       */
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
	add("Bonjour");
	add("comment ca va ?");
	add("Oui");
	/*int		fd;
	if ((fd = open("test.txt", O_RDONLY)) < 0)
		return (1);
	if ((close(fd)) < 0)
		return (1);*/
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 18:01:52 by mykman            #+#    #+#             */
/*   Updated: 2020/12/13 20:31:41 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
	int		fd;
	int		bytes;
	char	buf[BUFFER_SIZE + 1];

	if ((fd = open("test.txt", O_RDONLY)) < 0)
		return (1);

	bytes = read(fd, buf, BUFFER_SIZE);
	printf("%d : %s\n", bytes, buf);


	if ((close(fd)) < 0)
		return (1);
	return (0);
}
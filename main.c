/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 00:34:22 by mykman            #+#    #+#             */
/*   Updated: 2021/01/10 10:52:54 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "Bonus/get_next_line_bonus.h"

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
	int		ret;
	char	*str;

	str = NULL;
	if ((fd = open("beemovie.txt", O_RDONLY)) < 0)
		return (1);
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &str);
		if (ret < 0)
			break;
		printf("%d : '%s'\n", ret, str);
		free(str);
	}
	if ((close(fd)) < 0)
		return (1);
	return (0);
}

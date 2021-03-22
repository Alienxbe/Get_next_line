/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 00:34:22 by mykman            #+#    #+#             */
/*   Updated: 2021/02/18 16:59:10 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <time.h>
#include "Bonus/get_next_line_bonus.h"

int random_number(int min_num, int max_num);

void	add(char *str)
{
	static char	*a;

	if (!a)
		printf("First occurence\n");
	else
		printf("last occurence was : %s\n", a);
	a = str;
}


int random_number(int min_num, int max_num)
{
    int result = 0, low_num = 0, hi_num = 0;

    if (min_num < max_num)
    {
        low_num = min_num;
        hi_num = max_num + 1; // include max_num in output
    } else {
        low_num = max_num + 1; // include max_num in output
        hi_num = min_num;
    }

    srand(time(NULL));
    result = (rand() % (hi_num - low_num)) + low_num;
    return result;
}

int	ft_atoi(const char *str)
{
	unsigned long long	n;
	int					sign;
	int					i;

	if (!str)
		return (0);
	n = 0;
	i = 0;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\f' || str[i] == ' ')
		i++;
	sign = (str[i] == '-') ? -1 : 1;
	i = (str[i] == '-' || str[i] == '+') ? i + 1 : i;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + str[i++] - '0';
		if (n > LLONG_MAX)
			return ((sign == 1) ? -1 : 0);
	}
	return ((int)(n * sign));
}

int main(void)
{
	/*int		fd;
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
		return (1);*/
	int n;
	char *ans;

	n = random_number(1, 100);
	ans = "-1";
	while (ft_atoi(ans) != n)
	{
		printf("Choisis un nombre entre 1 et 100\n");
		get_next_line(1, &ans);
		if (ft_atoi(ans) > n)
			printf("Le nombre est plus petit\n");
		else if (ft_atoi(ans) < n)
			printf("Le nombre est plus grand\n");
		else
			printf("Bravo ! Tu as trouvé\n");
	}

	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hashly <hashly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 20:44:17 by hashly            #+#    #+#             */
/*   Updated: 2021/11/01 20:44:18 by hashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	fd = open("file", O_RDONLY);
	i = get_next_line(fd, &line);
	while (i)
	{
		printf("i = %d %s\n", i, line);
		free(line);
		i = get_next_line(fd, &line);
	}
	printf("i = %d %s\n", i, line);
	free(line);
	return (0);
}

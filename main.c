/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 12:28:25 by lnkambul          #+#    #+#             */
/*   Updated: 2019/07/10 15:19:44 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			main(int argc, char **argv)
{
	int		fd;
	char	*line;

	ft_putendl("line:");
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) && argc < 3)
	{
		ft_putendl("line:");
		ft_putendl(line);
		ft_strdel(&line);
	}
	return (0);
}

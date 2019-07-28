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

int			main()
{
	int		fd;
	char	*line;

	fd = open("Makefile", O_RDONLY);
	while (get_next_line(fd, &line))
	{
        if (line)
        {
	        ft_putendl(line);
            ft_strdel(&line);
        }
	}
	return (0);
}

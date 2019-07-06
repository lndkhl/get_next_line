/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksefeane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 10:49:32 by ksefeane          #+#    #+#             */
/*   Updated: 2019/07/06 01:25:12 by ksefeane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include "../libft/libft.h"
#include <fcntl.h>

int		ft_reader(const int fd, int n)
{
	char	*w;
	int		i;

	w = NULL;
	i = 0;
	while (i++ < n)
	{
		if (get_next_line(fd, &w) == 1)
		{
			ft_putendl(w);
			if (w)
				ft_strdel(&w);
		}
	}
	return (1);
}

int		main(int ac, char **av)
{
	int		fd;

/*	if (ac == 2 && ft_isdigit(av[1][0]))
	{
		fd = 1;
		ft_reader(fd, ft_atoi(av[1]));
	}
*/	if (ac == 3)
	{
		fd = open(av[1], O_RDONLY);
		ft_reader(fd, ft_atoi(av[2]));
	}
	return (0);
}

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

#include "../includes/get_next_line.h"

int	main(int argc, char **argv)
{
	int	fd;
	int	counter;
	char	*line;
	char	*file;

	counter = 1;
	while (counter < argc)
	{
		file = ft_strdup(argv[counter]);
		if (fd = open(file, O_RDONLY))
		{
			while (get_next_line(fd, &line))
			{
        			if (line)
        			{
					ft_putendl(line);
            				free(line);
        			}
			}
			free(file);
		}
		else
			ft_putendl("Error: File could not be found");
		counter++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 15:07:28 by lnkambul          #+#    #+#             */
/*   Updated: 2019/06/27 18:27:35 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		**buffer;

int				get_next_line(const int fd, char **line)
{
	char		*bank;
	char		*temp;
	size_t		i;

	buffer = (char**)malloc(sizeof(char *) * 1023);
	bank = ft_strnew(BUFF_SIZE);
	i = 2;
	while (read(fd, bank, BUFF_SIZE) > 0)
	{
		if(!ft_strchr(bank, '\n'));
		{
			temp = ft_strdup(bank);
			ft_strdel(&bank);
			free(bank);
			bank = ft_strnew(BUFF_SIZE * i++);
		}

		ft_strdel(line);
	}
	if (!buffer[fd])
		buffer = ft_strnew(
}

/*
int				main ()
{
	char	*fn;

	fn = ft_strdup("f1");

	ft_putendl(get_next_line(, &bank);
	return (0);
}
*/

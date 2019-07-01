/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 15:07:28 by lnkambul          #+#    #+#             */
/*   Updated: 2019/07/01 18:52:45 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include " get_next_line.h "
#include <fcntl.h>
#include <stdio.h>

int				get_next_line(const int fd, char **line)
{
	static t_lines	lines;
	t_lines			*node;

	char			*bank;
	char			*temp;

	if (fd < 0 || !line || read(fd, NULL, 0) == -1)
		return (-1);

	bank = ft_strnew(BUFF_SIZE);
	while (read(fd, bank, BUFF_SIZE * i) > 0)
	{
		if(!ft_strchr(bank, '\n'))
		{
			temp = ft_strdup(bank);
			ft_strdel(&bank);
			free(bank);
			bank = ft_strnew(BUFF_SIZE * ++i);
		}
		else
		{
			i = 0;
			while (ft_strchr(bank, '\n'))
			{
				while (bank[i] != *(ft_strchr(bank, '\n')))
					i++;
				temp = ft_strsub(bank, 0, i);
				bank += i;
				node = ft_lstnew(temp, i);
				i = 0;
				if (!(*buffer))
					*buffer = node;
				else
					ft_lstadd(buffer, node);
			}
			*line = (*buffer)->content;
			ft_lstdelone(buffer, ft_strdel(buffer), (*buffer)->content);
		}
	}
	return (1);
}

int			main()
{
	char *line = NULL;
	int fd;
	int output;

	fd = open( "", O_RDONLY);
	output = 1;

	while (output > 0)
	{
		output = get_next_line(fd, &line);
		printf("[%d] line: %s\n", output, line);
		ft_strdel(&line);
		line = NULL;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 15:07:28 by lnkambul          #+#    #+#             */
/*   Updated: 2019/07/03 16:56:45 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int					get_next_line(const int fd, char **line)
{
	static char		**arr;
	char			*bank;
	char			*temp;
	size_t			i;
	
	if (!(arr = (char **)malloc(sizeof(char *) * 1024)))
		return (-1);
	i = 0;
	while (i < 1024)
		arr[i++] = NULL;
	if (fd < 0 || !line || read(fd, NULL, 0) == -1)
		return (-1);
	bank = ft_strnew(BUFF_SIZE);
	while (read(fd, bank, BUFF_SIZE))
	{
		if(!(ft_strchr(bank, '\n')))
		{
			temp = (arr[fd]) ? ft_strjoin(arr[fd], bank) : ft_strdup(bank);
			ft_strdel(&bank);
			bank = NULL;
			bank = ft_strnew(BUFF_SIZE);
			arr[fd] = temp;
			ft_strdel(&temp);
			temp = NULL;
		}
		else
		{
			if (temp)
			{
				ft_strdel(&temp);
				temp = NULL;
			}
			while (bank[i] != *(ft_strchr(bank, '\n')))
				i++;
			*line = ft_strsub(bank, 0, i);
			arr[fd] = ft_strchr(bank, '\n');
			ft_strdel(&bank);
			bank = NULL;
			return (0);
		}
	}
	return (0);
}

#include <stdio.h>

int			main()
{
	char	*line = NULL;
	int 	fd;
	int 	output;

	fd = open( "makefile", O_RDONLY);
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

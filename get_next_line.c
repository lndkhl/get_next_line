/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 16:20:06 by lnkambul          #+#    #+#             */
/*   Updated: 2019/07/06 06:33:46 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	t(void)
{
	ft_putendl("1");
}

int					get_next_line(const int fd, char **line)
{
	static char		*arr[1024];
	char			*temp;

	if (fd < 0 || !line || read(fd, NULL, 0) == -1)
		return (-1);
	t();
	if (!((arr[fd]) && !(arr[fd] = ft_strnew(BUFF_SIZE))))
			return (-1);
	t();
	if (ft_strchr(arr[fd], '\n'))
	{
		t();
		*line = ft_strsub(arr[fd], 0, (size_t)(ft_strchr(arr[fd], '\n')\
						- arr[fd]));
		temp = ft_strsub(ft_strchr(arr[fd], '\n') + 1, 0,\
						ft_strlen(arr[fd]) - ft_strlen(*line));
		ft_strdel(&arr[fd]);
		arr[fd] = ft_strdup(temp);
		ft_strdel(&temp);
		return (1);
	}
	t();
	temp = ft_strnew(BUFF_SIZE);
	t();
	while (read(fd, temp, BUFF_SIZE))
	{
		t();
		arr[fd] = (arr[fd]) ? ft_strjoin(arr[fd], temp) : ft_strdup(temp);
		if (ft_strchr(arr[fd], '\n'))
		{
			t();
			*line = ft_strsub(arr[fd], 0, (size_t)(ft_strchr(arr[fd], '\n')\
						- arr[fd]));
			temp = ft_strsub(ft_strchr(arr[fd], '\n') + 1, 0,\
						ft_strlen(arr[fd]) - ft_strlen(*line));
			ft_strdel(&arr[fd]);
			arr[fd] = ft_strdup(temp);
			ft_strdel(&temp);
			return (1);
		}
		ft_strdel(&temp);
		temp = ft_strnew(BUFF_SIZE);
	}
	*line = (arr[fd]) ? arr[fd] : *line;
	if (arr[fd])
		ft_strdel(&arr[fd]);
	return (0);
}
/*
#include <stdio.h>

int			main()
{
	char	*line;
	int		fd;

	line = NULL;
	fd = open ("makefile", O_RDONLY);
	while (get_next_line(fd, &line))
	{
		printf("%s\n", line);
		ft_strdel(&line);
	}
	return (0);
}*/

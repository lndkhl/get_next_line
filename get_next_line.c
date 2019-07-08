/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 16:20:06 by lnkambul          #+#    #+#             */
/*   Updated: 2019/07/08 16:34:42 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int					get_next_line(const int fd, char **line)
{	
	static char		*arr[1024];
	char			*temp;
	int				i;

if (fd < 0 || !line || read(fd, NULL, 0) == -1)
		return (-1);
	if (!(arr[fd]) && !(arr[fd] = ft_strnew(BUFF_SIZE)))
			return (-1);
	if (ft_strchr(arr[fd], '\n'))
	{
		*line = ft_strsub(arr[fd], 0, (size_t)(ft_strchr(arr[fd], '\n')\
						- arr[fd]));
		temp = ft_strsub(ft_strchr(arr[fd], '\n') + 1, 0,\
						ft_strlen(arr[fd]) - ft_strlen(*line));
		ft_strdel(&arr[fd]);
		arr[fd] = ft_strdup(temp);
		ft_strdel(&temp);
		return (1);
	}
	temp = ft_strnew(BUFF_SIZE);
	if ((i = read(fd, temp, BUFF_SIZE)))
	{
		arr[fd] = (arr[fd]) ? ft_strjoin(arr[fd], temp) : ft_strdup(temp);
		if (ft_strchr(arr[fd], '\n'))
		{
			*line = ft_strsub(arr[fd], 0, (size_t)(ft_strchr(arr[fd], '\n')\
						- arr[fd]));
			ft_strdel(&temp);
			temp = ft_strsub(ft_strchr(arr[fd], '\n') + 1, 0,\
						ft_strlen(arr[fd]) - ft_strlen(*line));
			ft_strdel(&arr[fd]);
			arr[fd] = ft_strdup(temp);
			ft_strdel(&temp);
			return (1);
		}
		else if (i < BUFF_SIZE)
		{
			*line = ft_strdup(arr[fd]);
			ft_strdel(&arr[fd]);
			ft_strdel(&temp);
			return (1);
		}
	}
	if (i == 0 && arr[fd][0]){
		*line = ft_strdup(arr[fd]);
		ft_strdel(&arr[fd]);
		ft_strdel(&temp);
		return (1);
	}
	ft_strdel(&temp);
return (0);
}

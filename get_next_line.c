/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 10:32:19 by lnkambul          #+#    #+#             */
/*   Updated: 2019/07/17 17:20:46 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					get_next_line(const int fd, char **line)
{
	static char		*arr[4096];
	char			*temp;
	char			*t2;
	int				i;

if (fd < 0 || !line || read(fd, NULL, 0) == -1)
		return (-1);
	if (!(arr[fd]) && !(arr[fd] = ft_strnew(BUFF_SIZE)))
			return (-1);
	if (ft_strchr(arr[fd], '\n'))
	{
		if (!(*line = ft_strsub(arr[fd], 0, (ft_strchr(arr[fd], '\n') - arr[fd]))))
			return (-1);
		if (!(temp = ft_strsub(ft_strchr(arr[fd], '\n') + 1, 0,\
						ft_strlen(arr[fd]) - ft_strlen(*line))))
			return (-1);
		ft_strdel(&arr[fd]);
		arr[fd] = ft_strdup(temp);
		ft_strdel(&temp);
		return (1);
	}
	if (!(temp = ft_strnew(BUFF_SIZE)))
		return (-1);
	if ((i = read(fd, temp, BUFF_SIZE)))
	{
		if (!(t2 = (arr[fd]) ? ft_strjoin(arr[fd], temp) : ft_strdup(temp)))
			return (-1);
		ft_strdel(&arr[fd]);
		if (!(arr[fd] = ft_strdup(t2)))
			return (-1);
		ft_strdel(&t2);
		if (ft_strchr(arr[fd], '\n'))
		{
			if(!(*line = ft_strsub(arr[fd], 0, (ft_strchr(arr[fd], '\n') - arr[fd]))))
				return (-1);
			ft_strdel(&temp);
			if(!(temp = ft_strsub(ft_strchr(arr[fd], '\n') + 1, 0,\
						ft_strlen(arr[fd]) - ft_strlen(*line))))
				return (-1);
			ft_strdel(&arr[fd]);
			if (!(arr[fd] = ft_strdup(temp)))
				return (-1);
			ft_strdel(&temp);
			return (1);
		}
		else if (i < BUFF_SIZE)
		{
			if (!(*line = ft_strdup(arr[fd])))
				return (-1);
			ft_strdel(&arr[fd]);
			ft_strdel(&temp);
			return (1);
		}
		ft_strdel(&temp);
		return (1);
	}
	if (i == 0 && arr[fd][0]){
		if (!(*line = ft_strdup(arr[fd])))
			return (-1);
		ft_strdel(&arr[fd]);
		ft_strdel(&temp);
		return (1);
	}
	ft_strdel(&temp);
	return (0);
}

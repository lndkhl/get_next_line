/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 15:07:28 by lnkambul          #+#    #+#             */
/*   Updated: 2019/07/01 11:21:09 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list	**buffer;

static void		ft_del(void *c, size_t cs)
{
		ft_memdel(c);
}

int				get_next_line(const int fd, char **line)
{
	t_list		*node;
	char		*bank;
	char		*temp;
	size_t		i;

	bank = ft_strnew(BUFF_SIZE);
	i = 1;
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
			ft_lstdelone(buffer, ft_del((*buffer), (*buffer)->content_size));
		}
	}
	return (1);
}

int			main()
{
	return (0);
}

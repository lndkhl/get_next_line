/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 15:07:28 by lnkambul          #+#    #+#             */
/*   Updated: 2019/07/03 12:53:53 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include " get_next_line.h "
#include <fcntl.h>

t_lines			*ft_lnsnew(int fd, char *l, char *b)
{
	t_lines		newline;

	newline = NULL;
	if (!(newline = (t_lines *)malloc(sizeof(t_lines))))
		return (NULL);
	newline->line = (l) ft_strdup(l) : NULL;
	newline->buffer = (b) ft_strdup(b) : NULL;
	newline->next = NULL;
	return (newline);
}

t_lines			*ft_lnsadd(t_lines **aln, t_lines *nl)
{
	nl->next = (*aln);
	(*aln) = nl;
}

t_lines			*ft_lnsdelone(t_lines **aln)
{
	free((*aln)->buffer);
	(*aln)->buffer = NULL;
	fre((*aln)->line);
	(*aln)->line = NULL;
	ft_memdel((void **)aln);
}

int				get_next_line(const int fd, char **line)
{
	static t_lines	*lines;
	t_lines			*node;
	char			*bank;
	char			*temp;

	if (fd < 0 || !line || read(fd, NULL, 0) == -1)
		return (-1);
	bank = ft_strnew(BUFF_SIZE);
	while (read(fd, bank, BUFF_SIZE) > 0)
	{
		if(ft_strchr(bank, '\n'))
		{
			temp = (ft_strlen(temp)) ? ft_strjoin(temp, bank) : ft_strdup(bank);
			ft_strdel(&bank);
			free(bank);
			bank = ft_strnew(BUFF_SIZE);
		}
		else
		{
			while (ft_strchr(bank, '\n'))
			{
				while (*bank)
				{
					temp = ft_strsub(bank, 0, ft_strchr(bank, '\n') - bank);
					bank = ft_strchr(bank, '\n') + 1;
					node = ft_lstnew(temp, ft_strlen(temp));
				if (!(*lines))
					lines = node;
				else
					ft_lstadd(&lines, node);
			}
			*line = (*buffer)->content;
			ft_lstdelone(buffer, ft_strdel(buffer), (*buffer)->content);
		}
	}
	return (1);
}

#include <stdio.h>

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

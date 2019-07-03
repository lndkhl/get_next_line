/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 15:07:28 by lnkambul          #+#    #+#             */
/*   Updated: 2019/07/03 15:20:09 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include " get_next_line.h "
#include <fcntl.h>
/*
t_lines			*ft_lnsnew(int fd, char *l, char *b)
{
	t_lines		newline;

	newline = NULL;
	if (!(newline = (t_lines *)malloc(sizeof(t_lines))))
		return (NULL);
	newline->line = (l) ? ft_strdup(l) : NULL;
	newline->buffer = (b) ? ft_strdup(b) : NULL;
	newline->next = NULL;
	return (newline);
}

t_lines			*ft_lnsadd(int fd, t_lines **aln, t_lines *nl)
{
	nl->next = (*aln);
	(*aln) = nl;
}

t_lines			*ft_lnsdelone(int fd, t_lines **aln)
{
	free((*aln)->buffer);
	(*aln)->buffer = NULL;
	fre((*aln)->line);
	(*aln)->line = NULL;
	ft_memdel((void **)aln);
}
*/
int				get_next_line(const int fd, char **line)
{
	//static t_lines	**lines;
	static char		**arr;
	//t_lines		*node;
	char			*bank;
	char			*temp;
	/*
	if (!(lines = (t_lines **)malloc(sizeof(t_lines) * 1024)))
		return (-1);
	*/
	if (!(arr = (char **)malloc(sizeof(char *) * 1024)))
		return (-1);
	if (fd < 0 || !line || read(fd, NULL, 0) == -1)
		return (-1);
	bank = ft_strnew(BUFF_SIZE);
	while (read(fd, bank, BUFF_SIZE) > 0)
	{
		if(!(ft_strchr(bank, '\n')))
		{
			temp = (ft_strlen(temp)) ? ft_strjoin(temp, bank) : ft_strdup(bank);
			ft_strdel(&bank);
			free(bank);
			bank = ft_strnew(BUFF_SIZE);
		}
		else
		{
			*line = ft_strsub(bank, 0, size_t(ft_strchr(bank, '\n') - bank));
			temp = ft_strchr(bank, '\n') + 1;
			//node = ft_lnsnew(fd, temp, bank);
			arr[fd] = ft_strdup(temp);
			return (0);
		}
	}
	return (0);
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

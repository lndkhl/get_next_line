/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 15:12:57 by lnkambul          #+#    #+#             */
/*   Updated: 2019/07/01 18:52:54 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#define BUFF_SIZE 32
#include "libft.h"

typedef struct		s_lines
{
	int				fd;
	char			*buffer;
	char			*line;
	struct s_lines	*next;
}					t_lines;

int					get_next_line(const int fd, char **line);

#endif

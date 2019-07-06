/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 21:24:41 by lnkambul          #+#    #+#             */
/*   Updated: 2019/07/05 22:41:04 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"

void				get_fucked(char **line)
{
	static char		**t;
	static int		i = 0;
	int				j;

	if (!t)
		if(!(t = (char **)malloc(sizeof(char *) * 100)))
			return ;
	t[i] = *line;
	i += 1;
	if (i % 10 == 0)
	{
		j = 0;
		while (j < i)
			ft_putendl(t[j++]);
	}
}

int			main()
{
	char	*line;
	char	*other;
	int		i;

	i = 0;
	while (i++ < 100)
	{
		line = ft_itoa(i);
		get_fucked(&line);
	}
	other = ft_strdup("zero_fucks");
	line = ft_strsub(other, 0, (size_t)(ft_strchr(other, 'f') - other));
	ft_putendl(line);
	ft_putendl(ft_strsub(ft_strchr(other, '_') + 1, 0, ft_strlen(other) - ft_strlen(line)));
	return (0);
}

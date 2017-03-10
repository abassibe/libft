/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 13:49:33 by abassibe          #+#    #+#             */
/*   Updated: 2017/03/09 20:47:13 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

t_buff		*crea_lst(t_buff **buff, int fd, int chk)
{
	t_buff		*new;

	if (!(new = malloc(sizeof(t_buff))))
		return (NULL);
	new->fd = fd;
	new->ind = -1;
	new->buff = ft_strnew(BUFF_SIZE);
	new->next = NULL;
	if (chk)
	{
		new->next = *buff;
		*buff = new;
		return (new);
	}
	return (new);
}

t_buff		*check_buff(t_buff **cpy, int fd)
{
	while (*cpy)
	{
		if ((*cpy)->fd == fd)
			return (*cpy);
		*cpy = (*cpy)->next;
	}
	return (NULL);
}

int			clean_buff(t_buff *cpy, char **line, int fd)
{
	int		i;

	i = cpy->ind;
	if (i == -1)
		i = 0;
	while (cpy->buff[i])
	{
		if (cpy->buff[i] == '\n' || cpy->buff[i] == '\0')
		{
			*line = ft_strjoinf(*line, ft_strsub(cpy->buff, 0, i));
			cpy->buff = ft_strsubf(cpy->buff, i + 1, ft_strlen(cpy->buff));
			cpy->ind = 0;
			return (1);
		}
		i++;
	}
	*line = ft_strdup(cpy->buff);
	cpy->buff = ft_strnew(BUFF_SIZE);
	return (read_file(cpy, line, fd));
}

int			read_file(t_buff *cpy, char **line, int fd)
{
	int				i;
	int				ret;

	i = 0;
	ret = 0;
	while ((ret = read(fd, cpy->buff, BUFF_SIZE)) > 0)
	{
		cpy->buff[ret] = '\0';
		if (ft_strchr(cpy->buff, '\n') != NULL)
			return (clean_buff(cpy, line, fd));
		*line = ft_strjoinfn(*line, cpy->buff);
	}
	if (ret == -1)
		return (-1);
	if (*line[0] == 0)
		return (0);
	if (ret < BUFF_SIZE)
		free(cpy->buff);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static t_buff	*buff;
	t_buff			*cpy;

	if (line == NULL || fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	if (!buff)
		buff = crea_lst(NULL, fd, 0);
	cpy = buff;
	if (!check_buff(&cpy, fd))
		cpy = crea_lst(&buff, fd, 1);
	*line = ft_strnew(0);
	if (cpy->ind != -1)
		if (clean_buff(cpy, line, fd))
			return (1);
	return (read_file(cpy, line, fd));
}

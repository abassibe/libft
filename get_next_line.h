/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 13:50:58 by abassibe          #+#    #+#             */
/*   Updated: 2017/03/10 23:18:27 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# define BUFF_SIZE 9

typedef struct		s_buff
{
	int				fd;
	int				ind;
	char			*buff;
	struct s_buff	*next;
}					t_buff;

int					get_next_line(const int fd, char **line);
int					read_file(t_buff *cpy, char **line, int fd);

#endif
